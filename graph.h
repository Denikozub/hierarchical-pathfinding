#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include "types.h"

class Graph {
// public: Graph(...);
public: Graph(const Graph&);
public: Graph(Graph&&);
public: void clusterize();
public: id_set get_neighbours(uint64);
public: double get_weight(uint64, uint64);
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
