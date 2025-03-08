#ifndef JNGEN_INCLUDE_GRAPH_INL_H
#error File "graph_inl.h" must not be included directly.
#include "../graph.h" // for completion emgine
#endif

#include "../array.h"
#include "../common.h"
#include "../printers.h"

namespace jngen {

namespace graph_detail {

Graph BuilderProxy::g() const {
    return builder_(traits_);
}

BuilderProxy::operator Graph() const {
    return g();
}

class GraphRandom {
    using BuilderProxy = graph_detail::BuilderProxy;
    using Traits = graph_detail::Traits;

public:
    GraphRandom() {
        static bool created = false;
        ensure(!created, "jngen::GraphRandom should be created only once");
        created = true;
    }

    static BuilderProxy random(int n, int m) {
        ensure(
            n >= 0 && m >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n);
        checkLargeParameter(m);
        return BuilderProxy(Traits(n, m), &doRandom);
    }

    static BuilderProxy complete(int n) {
        ensure(
            n >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n * n);
        return BuilderProxy(Traits(n), [](Traits t) {
            Graph g;
            g.setN(t.n);
            if (t.directed) {
                g.directed_ = true;
            }
            for (int i = 0; i < t.n; ++i) {
                for (int j = 0; j <= i; ++j) {
                    if (i == j) {
                        if (t.allowLoops) {
                            g.addEdge(i, j);
                        }
                        continue;
                    }

                    if (t.directed) {
                        if (t.acyclic) {
                            g.addEdge(i, j);
                        } else if (t.allowAntiparallel) {
                            g.addEdge(i, j);
                            g.addEdge(j, i);
                        } else {
                            if (rnd.next(2)) {
                                g.addEdge(i, j);
                            } else {
                                g.addEdge(j, i);
                            }
                        }
                    } else {
                        g.addEdge(i, j);
                    }
                }
            }
            g.normalizeEdges();
            return g;
        });
    }

    static BuilderProxy empty(int n) {
        ensure(
            n >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n);
        return BuilderProxy(Traits(n), [](Traits t) {
            ensure(
                t.n <= 1 || !t.connected,
                "Empty graph on >1 vertices cannot be connected");
            Graph g;
            if (t.directed) {
                g.directed_ = true;
            }
            g.setN(t.n);
            return g;
        });
    }

    static BuilderProxy cycle(int n) {
        ensure(
            n >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n);
        return BuilderProxy(Traits(n), [](Traits t) {
            Graph g;
            if (t.directed) {
                g.directed_ = true;
                ensure(!t.acyclic, "Cannot generate acyclic cycle");
            }
            for (int i = 0; i < t.n; ++i) {
                g.addEdge(i, (i+1)%t.n);
            }
            g.normalizeEdges();
            return g;
        });
    }

    static BuilderProxy randomStretched(
            int n, int m, int elongation, int spread)
    {
        ensure(
            n >= 0 && m >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n);
        checkLargeParameter(m);
        return BuilderProxy(Traits(n, m), [elongation, spread](Traits t) {
            return doRandomStretched(t, elongation, spread);
        });
    }

    static BuilderProxy randomBipartite(int n1, int n2, int m) {
        ensure(
            n1 >= 0 && n2 >= 0 && m >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n1 + n2);
        checkLargeParameter(m);
        return BuilderProxy(Traits(0, m), [n1, n2](Traits t) {
                return doRandomBipartite(t, n1, n2);
        });
    }


    static BuilderProxy completeBipartite(int n1, int n2) {
        ensure(
            n1 >= 0 && n2 >= 0,
            "Number of vertices and edges in the graph must be nonnegative");
        checkLargeParameter(n1 * n2);
        return BuilderProxy(Traits(0, 0), [n1, n2](Traits t) {
            ensure(!t.directed, "Directed bipartite graphs are not supported");

            Arrayp edges;
            edges.reserve(n1 * n2);
            for (int u = 0; u < n1; ++u) {
                for (int v = 0; v < n2; ++v) {
                    edges.emplace_back(u, v + n1);
                }
            }

            Graph g;
            g.initWithEdges(n1 + n2, edges);
            return g;
        });
    }

private:
    static Graph doRandom(Traits t) {
        int n = t.n;
        int m = t.m;

        if (!t.allowMulti) {
            ensure(m <= maxEdges(n, t), "Too many edges in the graph");
        }

        std::unordered_set<std::pair<int, int>> usedEdges;

        if (t.connected) {
            ensure(m >= n - 1, "Not enough edges for a connected graph");
            auto treeEdges = Tree::random(n).edges();
            if (t.directed) {
                for (auto& edge: treeEdges) {
                    if (rnd.next(2)) {
                        std::swap(edge.first, edge.second);
                    }
                }
            }
            usedEdges.insert(treeEdges.begin(), treeEdges.end());
            ENSURE(usedEdges.size() == static_cast<size_t>(n - 1));
        }

        auto edgeIsGood = [&usedEdges, t](std::pair<int, int> edge) {
            if (!t.allowMulti && usedEdges.count(edge)) {
                return false;
            }
            if (t.directed && !t.allowAntiparallel &&
                    usedEdges.count({edge.second, edge.first}))
            {
                return false;
            }
            return true;
        };

        Arrayp result(usedEdges.begin(), usedEdges.end());
        result.reserve(m);

        while (result.size() < static_cast<size_t>(m)) {
            auto edge = randomEdge(n, t);
            if (edgeIsGood(edge)) {
                usedEdges.insert(edge);
                result.push_back(edge);
            }
        }

        Graph graph;

        if (t.directed && t.acyclic) {
            makeAcyclic(result);
        }
        if (t.directed) {
            graph.directed_ = true;
        }

        graph.initWithEdges(n, result);
        return graph;
    }

    static Graph doRandomStretched(Traits t, int elongation, int spread) {
        Tree tree = Tree::randomPrim(t.n, elongation);
        Array parents = tree.parents(0);
        parents[0] = 0;


        auto treeEdges = tree.edges();
        if (t.directed && !t.acyclic) {
            for (auto& edge: treeEdges) {
                if (rnd.next(2)) {
                    std::swap(edge.first, edge.second);
                }
            }
        }

        Arrayp edges = treeEdges;
        edges.reserve(t.m);

        std::unordered_set<std::pair<int, int>> usedEdges(
            treeEdges.begin(), treeEdges.end());

        auto edgeIsGood = [&usedEdges, t](std::pair<int, int> edge) {
            if (!t.allowMulti && usedEdges.count(edge)) {
                return false;
            }
            if (t.directed && !t.allowAntiparallel &&
                    usedEdges.count({edge.second, edge.first}))
            {
                return false;
            }
            return true;
        };

        constexpr size_t MAX_ATTEMPTS = 1000;
        size_t attemptsToFail = MAX_ATTEMPTS;

        while (static_cast<int>(edges.size()) != t.m) {
            if (--attemptsToFail == 0) {
                ensure(false, format("Cannot generate random stretched graph "
                    "with parameters %d, %d, %d, %d",
                    t.n, t.m, elongation, spread));
            }
            int u = rnd.next(t.n);
            int up = rnd.next(0, spread);
            int v = u;
            for (int iter = 0; iter < up; ++iter) {
                v = parents[v];
            }

            ENSURE(v <= u);

            if (!t.allowLoops && u == v) {
                continue;
            }

            if (!edgeIsGood({v, u})) {
                continue;
            }

            if (t.directed && !t.acyclic && rnd.next(2)) {
                std::swap(u, v);
            }

            edges.emplace_back(v, u);
            attemptsToFail = MAX_ATTEMPTS;
        }

        Graph graph;
        if (t.directed) {
            graph.directed_ = true;
        }

        graph.initWithEdges(t.n, edges);
        return graph;
    }

    static Graph doRandomBipartite(Traits t, int n1, int n2) {
        int m = t.m;

        if (!t.allowMulti) {
            ensure(m <= static_cast<long long>(n1) * n2,
                    "Too many edges in the graph");
        }

        ensure(!t.directed, "Directed bipartite graphs are not supported");

        std::unordered_set<std::pair<int, int>> usedEdges;

        if (t.connected) {
            ensure(m >= n1 + n2 - 1, "Not enough edges for a connected graph");
            auto pruferCode = Array::random(n2 - 1, 0, n1 - 1) +
                Array::random(n1 - 1, n1, n1 + n2 - 1);
            pruferCode.shuffle();
            auto treeEdges = Tree::fromPruferSequence(pruferCode).edges();
            usedEdges.insert(treeEdges.begin(), treeEdges.end());
            ENSURE(usedEdges.size() == static_cast<size_t>(n1 + n2 - 1));
        }

        auto edgeIsGood = [&usedEdges, t](std::pair<int, int> edge) {
            if (!t.allowMulti && usedEdges.count(edge)) {
                return false;
            }
            if (t.directed && !t.allowAntiparallel &&
                    usedEdges.count({edge.second, edge.first}))
            {
                return false;
            }
            return true;
        };

        Arrayp result(usedEdges.begin(), usedEdges.end());
        result.reserve(m);

        while (result.size() < static_cast<size_t>(m)) {
            int u = rnd.next(0, n1 - 1);
            int v = rnd.next(n1, n1 + n2 - 1);
            std::pair<int, int> edge(u, v);
            if (edgeIsGood(edge)) {
                usedEdges.insert(edge);
                result.push_back(edge);
            }
        }

        Graph graph;

        graph.initWithEdges(n1 + n2, result);
        return graph;
    }

    static std::pair<int, int> randomEdge(int n, const Traits& t) {
        return rnd.nextp(n, RandomPairTraits{!t.directed, !t.allowLoops});
    }

    static long long maxEdges(int n, const Traits& t) {
        ENSURE(!t.allowMulti);
        long long res = static_cast<long long>(n) * (n-1);
        if (!(t.directed && t.allowAntiparallel)) {
            res /= 2;
        }
        if (t.allowLoops) {
            res += n;
        }
        return res;
    }

    static void makeAcyclic(Arrayp& edges) {
        auto numbering = Array::id(edges.size()).shuffle();
        for (auto& edge: edges) {
            if (numbering[edge.first] > numbering[edge.second]) {
                std::swap(edge.first, edge.second);
            }
        }
    }
};

} // namespace graph_detail

Graph::BuilderProxy Graph::random(int n, int m) {
    return graph_detail::GraphRandom::random(n, m);
}

Graph::BuilderProxy Graph::complete(int n) {
    return graph_detail::GraphRandom::complete(n);
}

Graph::BuilderProxy Graph::empty(int n) {
    return graph_detail::GraphRandom::empty(n);
}

Graph::BuilderProxy Graph::cycle(int n) {
    return graph_detail::GraphRandom::cycle(n);
}

Graph::BuilderProxy Graph::randomStretched(
        int n, int m, int elongation, int spread) {
    return graph_detail::GraphRandom::randomStretched(n, m, elongation, spread);
}

Graph::BuilderProxy Graph::randomBipartite(int n1, int n2, int m) {
    return graph_detail::GraphRandom::randomBipartite(n1, n2, m);
}

Graph::BuilderProxy Graph::completeBipartite( int n1, int n2) {
    return graph_detail::GraphRandom::completeBipartite(n1, n2);
}

} // namespace jngen
