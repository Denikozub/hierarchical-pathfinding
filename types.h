#ifndef HIERARCHICAL_PATHFINDING_TYPES_H
#define HIERARCHICAL_PATHFINDING_TYPES_H

#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include "path.h"

class PairHash;
typedef std::unordered_set<std::pair<uint64_t, Path>, PairHash> adj_nodes;
typedef std::unordered_map<uint64_t, adj_nodes> adj_list;

class PairHash {
public:
    size_t operator()(const std::pair<uint64_t, Path> &p) const {
        return p.first + PathHash()(p.second);
    }
};

#endif //HIERARCHICAL_PATHFINDING_TYPES_H
