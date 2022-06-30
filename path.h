#ifndef HIERARCHICAL_PATHFINDING_PATH_H
#define HIERARCHICAL_PATHFINDING_PATH_H

#include <vector>
#include <string>
#include "types.h"
#include "node.h"

class Path {
private: const node_map* nodes;
private: std::vector<uint64> path {};
private: double weight {0};
public: explicit Path(const node_map*);
public: void add(uint64, double);
public: void add(const Path&);
public: void to_gpx(std::string) const;
public: [[nodiscard]] double get_weight() const;
};

#endif //HIERARCHICAL_PATHFINDING_PATH_H
