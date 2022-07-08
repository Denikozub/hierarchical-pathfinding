#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest/doctest/doctest.h"
#include "../src/node.h"
#include "../src/haversine.h"
#include "../src/path.h"
#include "../src/graph.h"

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

TEST_CASE("function haversine") {
    SUBCASE("distance 1") {
        double lat1 = 55.388, lon1 = 38.68869, lat2 = 55.36447, lon2 = 38.76534;
        Node n1(lat1, lon1), n2(lat2, lon2);
        CHECK(haversine(n1, n2) >= 5.45);
        CHECK(haversine(n1, n2) <= 5.55);
        CHECK(haversine(n1, lat2, lon2) >= 5.45);
        CHECK(haversine(n1, lat2, lon2) <= 5.55);
        CHECK(haversine(lat1, lon1, n2) >= 5.45);
        CHECK(haversine(lat1, lon1, n2) <= 5.55);
        CHECK(haversine(lat1, lon1, lat2, lon2) >= 5.45);
        CHECK(haversine(lat1, lon1, lat2, lon2) <= 5.55);
    }
    SUBCASE("distance 2") {
        double lat1 = 47.085, lon1 = -80.7055, lat2 = 50.48556, lon2 = -86.792;
        Node n1(lat1, lon1), n2(lat2, lon2);
        CHECK(haversine(n1, n2) >= 584);
        CHECK(haversine(n1, n2) <= 586);
        CHECK(haversine(n1, lat2, lon2) >= 584);
        CHECK(haversine(n1, lat2, lon2) <= 586);
        CHECK(haversine(lat1, lon1, n2) >= 584);
        CHECK(haversine(lat1, lon1, n2) <= 586);
        CHECK(haversine(lat1, lon1, lat2, lon2) >= 584);
        CHECK(haversine(lat1, lon1, lat2, lon2) <= 586);
    }
}

TEST_CASE("class Path") {
    Path p1, p2;
    SUBCASE("add") {
        p1.add(1, 1);
        p1.add(2, 2);
        p2.add(p1);
        CHECK(p1 == p2);
    }
    SUBCASE("reverse") {
        p1.add(1, 1);
        p1.add(2, 2);
        p1.add(3, 3);
        p2.add_reversed(p1);
        p2.reverse();
        CHECK(p1 == p2);
    }
    SUBCASE("to gpx") {
        p1.add(1, 1);
        p1.add(2, 2);
        p1.add(3, 3);
        node_map nodes = {{0, Node(0, 0)}, {1, Node(1, 1)}, {2, Node(2, 2)}, {3, Node(3, 3)}};
        p1.to_gpx(0, "unittest_track.gpx", &nodes);
    }
}
