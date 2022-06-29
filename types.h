#ifndef HIERARCHICAL_PATHFINDING_TYPES_H
#define HIERARCHICAL_PATHFINDING_TYPES_H

#include <unordered_map>
#include <unordered_set>
#include "node.h"
#include "edge.h"

typedef unsigned long long uint64;
typedef std::unordered_map<uint64, Node> node_map;
typedef std::unordered_set<uint64> id_set;
typedef std::unordered_set<Edge> edge_set;
typedef std::unordered_map<uint64, unordered_set<uint64>> adj_list;

#endif //HIERARCHICAL_PATHFINDING_TYPES_H
