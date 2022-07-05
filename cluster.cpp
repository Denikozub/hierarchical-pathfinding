#include "graph.h"

std::set<std::unordered_set<uint64_t>> Graph::find_clusters(double) {
    // set all Nodes to default
}

void Graph::clusterize(double threshold) {
    int cluster_no = 0;
    for (const auto& cluster_nodes : find_clusters(threshold)) {
        std::unordered_set<uint64_t> outer_nodes;
        for (uint64_t cluster_node: cluster_nodes) {
            for (const auto& [neighbour, _] : *get_neighbours(cluster_node)) {
                if (!cluster_nodes.contains(neighbour)) {
                    outer_nodes.insert(cluster_node);
                    nodes.at(cluster_node).set_outer(true);
                    break;
                }
            }
            nodes.at(cluster_node).set_cluster_no(cluster_no);
        }
        adj_list outer_neighbours_map;
        for (uint64_t outer_node : outer_nodes) {
            outer_neighbours_map[outer_node] = {};
            for (uint64_t neighbour : outer_nodes) {
                if (outer_node == neighbour) {
                    continue;
                }
                Path path = find_path_astar(outer_node, neighbour, *this);
                if (!path.empty()) {
                    outer_neighbours_map[outer_node].insert({neighbour, path});
                }
            }
        }
        clusters[cluster_no] = outer_neighbours_map;
        ++cluster_no;
    }
}
