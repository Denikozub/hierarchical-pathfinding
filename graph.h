#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include <cstdint>
#include "types.h"
#include "cluster.h"
#include "pugixml/src/pugixml.hpp"

/*
 * Constructors initialize nodes and node_neighbours_map;
 * Graph::clusterize() initializes clusters and updates Node::cluster_no;
 */

class Graph {
private:
    node_map nodes = node_map{};
    adj_list node_neighbours_map = adj_list{};
    cluster_map clusters {};
public:
    Graph(const std::string&);
    void clusterize();
    const adj_nodes* get_neighbours(uint64_t) const;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
