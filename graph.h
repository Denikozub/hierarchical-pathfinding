#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include <cstdint>
#include "types.h"
#include "cluster.h"

class Graph {
private:
    node_map nodes;
    adj_list node_neighbours;
    cluster_map clusters {};
public:
    // Graph(...);
    void clusterize();
    const adj_nodes* get_neighbours(uint64_t) const;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
