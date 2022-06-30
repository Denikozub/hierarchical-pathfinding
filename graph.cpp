#include "graph.h"

const adj_nodes* Graph::get_neighbours(uint64_t id) const {
    if (nodes.at(id).has_cluster() && nodes.at(id).is_outer()) {
        uint64_t cluster_id = nodes.at(id).get_cluster_no();
        return clusters.at(cluster_id).get_outer_neighbours(id);
    }
    return &node_neighbours_map.at(id);
}
