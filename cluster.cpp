#include "graph.h"

void Graph::clusterize(double threshold) {

}

//void Cluster::compute() {
//    std::unordered_set<uint64_t> outer_nodes;
//    for (uint64_t cluster_node: cluster_nodes) {
//        for (const auto& [neighbour, _] : (*node_neighbours_map).at(cluster_node)) {
//            if (!cluster_nodes.contains(neighbour)) {
//                outer_nodes.insert(cluster_node);
//                (*nodes).at(cluster_node).set_outer(true);
//            }
//        }
//    }
//    for (uint64_t outer_node : outer_nodes) {
//        outer_neighbours_map[outer_node] = {};
//        for (uint64_t neighbour : outer_nodes) {
//            Path path = find_path_astar(outer_node, neighbour, nodes, node_neighbours_map);
//            if (!path.empty()) {
//                outer_neighbours_map[outer_node].insert({neighbour, path});
//            }
//        }
//    }
//}
