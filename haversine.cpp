#include "haversine.h"
#include <cmath>

double haversine(const Node& node1, const Node& node2) {
    double lat1 = node1.get_lat(), lon1 = node1.get_lon(), \
           lat2 = node2.get_lat(), lon2 = node2.get_lon();
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    return 6371 * 2 * asin(sqrt(a));
}
