#ifndef HIERARCHICAL_PATHFINDING_ASTAR_H
#define HIERARCHICAL_PATHFINDING_ASTAR_H

#include "path.h"
#include "graph.h"
#include "cstdint"

Path find_path_astar(uint64_t start, uint64_t goal, const Graph&, double heuristic_multiplier = 10);

#endif //HIERARCHICAL_PATHFINDING_ASTAR_H