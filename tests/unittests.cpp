#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest/doctest/doctest.h"
#include "../src/node.h"

TEST_CASE("class Node") {
    Node n(0, 0);
    SUBCASE("defaults") {
        CHECK(!n.is_outer());
        CHECK(!n.has_cluster());
    }
    SUBCASE("getters and setters") {
        n.set_lon(1);
        n.set_lat(2);
        n.set_cluster_no(3);
        n.set_outer(true);
        CHECK(n.get_lon() == 1);
        CHECK(n.get_lat() == 2);
        CHECK(n.get_cluster_no() == 3);
        CHECK(n.is_outer());
    }
    SUBCASE("resetting") {
        n.set_cluster_no(3);
        n.set_outer(true);
        n.reset_cluster_data();
        CHECK(!n.is_outer());
        CHECK(!n.has_cluster());
    }
}

TEST_CASE("class Path") {
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    SUBCASE("adding to the vector increases it's size") {
        v.push_back(1);

        CHECK(v.size() == 6);
        CHECK(v.capacity() >= 6);
    }
    SUBCASE("reserving increases just the capacity") {
        v.reserve(6);

        CHECK(v.size() == 5);
        CHECK(v.capacity() >= 6);
    }
}
