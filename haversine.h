#ifndef HIERARCHICAL_PATHFINDING_HAVERSINE_H
#define HIERARCHICAL_PATHFINDING_HAVERSINE_H

#include "node.h"

// return distance in km
double haversine(const Node&, const Node&);
double haversine(double lat, double lon, const Node&);
double haversine(const Node&, double lat, double lon);
double haversine(double lat1, double lon1, double lat2, double lon2);

#endif //HIERARCHICAL_PATHFINDING_HAVERSINE_H
