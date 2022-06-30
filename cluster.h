#ifndef HIERARCHICAL_PATHFINDING_CLUSTER_H
#define HIERARCHICAL_PATHFINDING_CLUSTER_H

#include <cstdint>
#include <unordered_set>
#include "types.h"

class Cluster;
typedef std::unordered_map<uint64_t, Cluster> cluster_map;

/*
 * ONLY requires node_map* to update Node::is_outer_;
 * Outer check: has incident nodes NOT from cluster;
 * Cluster::compute() precomputes outer_neighbours_map and updates Node::is_outer_;
 */

class Cluster {
private:
    node_map* nodes = nullptr;
    const adj_list* node_neighbours_map = nullptr;
    adj_list outer_neighbours_map {};
    const std::unordered_set<uint64_t> cluster_nodes {};
public:
    Cluster(node_map*, const adj_list*, std::unordered_set<uint64_t>&&);
    void compute();
    const adj_nodes* get_outer_neighbours(uint64_t) const;
};

#endif //HIERARCHICAL_PATHFINDING_CLUSTER_H
