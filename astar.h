#ifndef HIERARCHICAL_PATHFINDING_ASTAR_H
#define HIERARCHICAL_PATHFINDING_ASTAR_H

#include "path.h"
#include "types.h"
#include "cstdint"

Path find_path_astar(uint64_t, uint64_t, const node_map&, const adj_list&);

#endif //HIERARCHICAL_PATHFINDING_ASTAR_H
