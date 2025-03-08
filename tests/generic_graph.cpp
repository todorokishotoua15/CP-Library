#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../jngen.h"

#include <sstream>

using jngen::GenericGraph;

BOOST_AUTO_TEST_SUITE(generic_graph)

BOOST_AUTO_TEST_CASE(basics) {
    GenericGraph gg;

    BOOST_TEST(gg.n() == 0);
    BOOST_TEST(gg.m() == 0);
    BOOST_TEST(gg.isConnected());
    BOOST_TEST(gg.edges().empty());

    gg.addEdge(0, 2);
    gg.addEdge(1, 3);
    BOOST_TEST(gg.edges().size() == 2);
    BOOST_CHECK(gg.edges()[0] == std::make_pair(0, 2));
    BOOST_CHECK(gg.edges()[1] == std::make_pair(1, 3));
    BOOST_TEST(gg.n() == 4);
    BOOST_TEST(gg.m() == 2);
    BOOST_TEST(!gg.isConnected());

    gg.addEdge(0, 3);
    BOOST_TEST(gg.isConnected());
    gg.addEdge(0, 3);
    BOOST_TEST(gg.m() == 4);

    auto g2 = gg;
    BOOST_CHECK(gg == g2);
    g2.addEdge(1, 2);
    BOOST_CHECK(!(gg == g2));
}

BOOST_AUTO_TEST_SUITE_END()
