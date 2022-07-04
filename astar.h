#ifndef HIERARCHICAL_PATHFINDING_ASTAR_H
#define HIERARCHICAL_PATHFINDING_ASTAR_H

#include "path.h"
#include "graph.h"
#include "cstdint"

Path find_path_astar(uint64_t, uint64_t, const Graph&, double=10);

#endif //HIERARCHICAL_PATHFINDING_ASTAR_H