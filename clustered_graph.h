#ifndef HIERARCHICAL_PATHFINDING_CLUSTERED_GRAPH_H
#define HIERARCHICAL_PATHFINDING_CLUSTERED_GRAPH_H

#include "graph.h"

class ClusteredGraph : Graph {
// public: Graph(...);
public: ClusteredGraph(const ClusteredGraph&);
public: ClusteredGraph(ClusteredGraph&&);
public: void clusterize();
public: id_set get_neighbours(uint64) override;
public: double get_weight(uint64, uint64) override;
};

#endif //HIERARCHICAL_PATHFINDING_CLUSTERED_GRAPH_H
