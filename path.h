#ifndef HIERARCHICAL_PATHFINDING_PATH_H
#define HIERARCHICAL_PATHFINDING_PATH_H

#include <vector>
#include <string>
#include <cstdint>
#include "node.h"

/*
 * Needs node_map* for GPX output;
 * Does not include start node!!!
 */

class Path {
private:
    std::vector<uint64_t> path {};
    double weight {0};
    friend class PathHash;
public:
    void add(uint64_t, double);
    void add(const Path&);
    void add_reversed(const Path&);
    void to_gpx(std::string, const node_map*) const;
    double get_weight() const;
    bool empty() const;
    void reverse();
};

class PathHash {
public: size_t operator()(const Path&) const;
};

#endif //HIERARCHICAL_PATHFINDING_PATH_H
