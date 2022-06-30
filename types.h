#ifndef HIERARCHICAL_PATHFINDING_TYPES_H
#define HIERARCHICAL_PATHFINDING_TYPES_H

#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include "path.h"

typedef std::unordered_set<std::pair<uint64_t, Path>, PathHash> adj_nodes;
typedef std::unordered_map<uint64_t, adj_nodes> adj_list;

#endif //HIERARCHICAL_PATHFINDING_TYPES_H
