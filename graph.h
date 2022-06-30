#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include "types.h"

class Graph {
public: virtual id_set get_neighbours(uint64) = 0;
public: virtual double get_weight(uint64, uint64) = 0;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
