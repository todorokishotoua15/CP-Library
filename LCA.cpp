class LCA {
public:
    vector<vector<int>> adj;
    vector<int> vis,vis_cent;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> cent_tree;
    vector<int> par;
    vector<int> subtree,sub,start,end;
    int n;
 
    LCA(int size) {
        adj = vector<vector<int>> (size+1);
        cent_tree = vector<vector<int>> (size+1);
        vis = vector<int> (size+1 , 0);
        vis_cent = vector<int> (size+1 , 0);
        up = vector<vector<int>> (size+1, vector<int>(20));
        depth = vector<int>(size+1);
        par = vector<int>(size+1,-1);
        subtree = vector<int>(size+1,0);
        sub = vector<int>(size+1,0);
        start = vector<int>(size+1,0);
        end = vector<int>(size+1,0);
        n = size;
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int timer = 0;
    void dfs(int node) {
 
        vis[node] = 1;
        sub[node] = 1;
        timer++;
        start[node] = timer;
        for (int i = 1; i < 20; i++) {
            up[node][i] = up[ up[node][i-1] ][i-1];
        }
      
        for (auto x : adj[node]) {
            if (vis[x] == 0) {
                depth[x] = depth[ up[x][0] = node ] + 1;
                dfs(x);
                sub[node] += sub[x];
            }
        }
        timer++;
        end[node] = timer;
    }
 
    int jump(int x, int d) {
        for (int i = 0; i < 20; i++) {
            if ((d >> i) & 1) {
                x = up[x][i];
            }
        }
        return x;
    }
 
    int lca(int a, int b) {
 
        if (depth[a] < depth[b]) swap(a,b);
 
        a = jump(a,depth[a]-depth[b]);
        if (a == b) return a;
 
        for (int i = 19; i >= 0; i--) {
            int aT = up[a][i], bT = up[b][i];
            if (aT != bT) a = aT, b = bT;
        }
 
        return up[a][0];
 
    }

    int dis(int a, int b) {
        int lc = lca(a,b);
        return depth[a] + depth[b] - 2*depth[lc];
    }

    int centroid(int root) {
        
        int sz = 0;
        auto dfs1 = [&] (auto self,int node,int p) -> void {
            sz++;
            subtree[node] = 1;
            for (auto x : adj[node]) {
                if (vis_cent[x] == 0 && x != p) {
                    self(self,x,node);
                    subtree[node] += subtree[x];
                }
            }
        };

        auto dfs2 = [&] (auto self, int node,int p) -> int {
            for (auto x : adj[node]) {
                if (vis_cent[x] == 0 && x != p) {
                    if (subtree[x] > sz/2) {
                        return self(self,x,node);
                    }
                }
            }
            return node;
        };
        dfs1(dfs1,root,-1);
        int c = dfs2(dfs2,root,-1);
        vis_cent[c] = 1;
        return c;
    }

    void create_cent_tree (int root, int p = -1) {
        int c = centroid(root);
        par[c] = p;
        for (auto x : adj[c]) {
            if (vis_cent[x] == 0) {
                create_cent_tree(x,c);
            }
        }
    }
 
};

