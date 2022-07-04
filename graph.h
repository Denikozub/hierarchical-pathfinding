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

class Graph;
Graph from_graphml(const std::string&);

class Graph {
private:
    node_map nodes = node_map{};
    adj_list node_neighbours_map = adj_list{};
    cluster_map clusters {};
    friend Graph from_graphml(const std::string&);
public:
    void clusterize();
    const adj_nodes* get_neighbours(uint64_t) const;
    const Node* get_node(uint64_t) const;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
