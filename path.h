#ifndef HIERARCHICAL_PATHFINDING_PATH_H
#define HIERARCHICAL_PATHFINDING_PATH_H

#include "node.h"
#include <string>

class Path {
public: Path();
public: Path(const Path&);
public: Path(Path&&);
public: void add(const Node&, const Node&);
public: void add(const Path&);
public: void to_gpx(std::string);
};

#endif //HIERARCHICAL_PATHFINDING_PATH_H
