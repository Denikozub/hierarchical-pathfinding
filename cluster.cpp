#include "cluster.h"

Cluster::Cluster(node_map* new_nodes, const adj_list* new_node_neighbours_map, \
    std::unordered_set<uint64_t>&& new_cluster_nodes) : \
    nodes(new_nodes), node_neighbours_map(new_node_neighbours_map), cluster_nodes(new_cluster_nodes) {}

const adj_nodes* Cluster::get_outer_neighbours(uint64_t id) const {
    return &outer_neighbours_map.at(id);
}