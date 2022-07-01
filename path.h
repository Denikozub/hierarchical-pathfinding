#ifndef HIERARCHICAL_PATHFINDING_PATH_H
#define HIERARCHICAL_PATHFINDING_PATH_H

#include <vector>
#include <string>
#include <cstdint>
#include "node.h"

/*
 * Needs node_map* for GPX output;
 */

class Path {
private:
    const node_map* nodes = nullptr;
    std::vector<uint64_t> path {};
    double weight {0};
    friend class PathHash;
public:
    explicit Path(const node_map*);
    void add(uint64_t, double);
    void add(const Path&);
    void to_gpx(std::string) const;
    double get_weight() const;
};

class PathHash {
public:
    size_t operator()(const Path &p) const;
};

#endif //HIERARCHICAL_PATHFINDING_PATH_H
