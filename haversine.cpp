#include "haversine.h"
#include <cmath>

double haversine(const Node& node1, const Node& node2) {
    return haversine(node1.get_lat(), node1.get_lon(), node2.get_lat(), node2.get_lon());
}

double haversine(double lat, double lon, const Node& node) {
    return haversine(lat, lon, node.get_lat(), node.get_lon());
}

double haversine(const Node& node, double lat, double lon) {
    return haversine(lat, lon, node.get_lat(), node.get_lon());
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    return 6371 * 2 * asin(sqrt(a));
}
