#include "graph.h"
#include "haversine.h"

#define CLUSTER_MERGE_ITER_COUNT 20
#define MIN_CLUSTER_SIZE_PERCENT 1

class Cluster {
    double lat, lon;
    int count{0};
    std::unordered_set<uint64_t> cluster_nodes{};
public:
    void add_node(uint64_t id, const Node& node) {
        cluster_nodes.insert(id);
        lat = (lat * count + node.get_lat()) / (count + 1);
        lon = (lon * count + node.get_lon()) / (count + 1);
        ++count;
    }
    void add_cluster(Cluster&& other) {
        cluster_nodes.insert(other.cluster_nodes.begin(), other.cluster_nodes.end());
        lat = (lat * count + other.lat * other.count) / (count + other.count);
        lon = (lon * count + other.lon * other.count) / (count + other.count);
        count += other.count;
    }
    std::unordered_set<uint64_t> move_nodes() {
        return std::move(cluster_nodes);
    }
    double distance(const Node& node) const {
        return haversine(node, lat, lon);
    }
    double distance(const Cluster& other) const {
        return haversine(lat, lon, other.lat, other.lon);
    }
    size_t node_count() const {
        return cluster_nodes.size();
    }
    friend bool operator== (const Cluster& cluster_1, const Cluster& cluster_2) {
        return cluster_1.cluster_nodes == cluster_2.cluster_nodes;
    }
};

std::vector<std::unordered_set<uint64_t>> Graph::find_clusters(double threshold) const {
    std::vector<Cluster> cluster_set{};
    int it_num = 0;
    for (const auto& [id, node] : nodes) {
        for (auto& cluster: cluster_set) {
            if (cluster.distance(node) <= threshold) {
                cluster.add_node(id, node);
                break;
            }
        }
        // combine clusters
        if (it_num % int(1 + nodes.size() / CLUSTER_MERGE_ITER_COUNT) == 0) {
            for (auto& cluster_1: cluster_set) {
                for (auto& cluster_2: cluster_set) {
                    if (cluster_1 == cluster_2) {
                        continue;
                    }
                    if (cluster_1.distance(cluster_2) <= threshold) {
                        cluster_1.add_cluster(std::move(cluster_2));
                    }
                }
            }
        }
    }
    std::vector<std::unordered_set<uint64_t>> final_clusters{};
    for (auto& cluster: cluster_set) {
        if (cluster.node_count() / nodes.size() * 100 >= MIN_CLUSTER_SIZE_PERCENT) {
            final_clusters.push_back(cluster.move_nodes());
        }
    }
    return std::move(final_clusters);
}

void Graph::clusterize(double threshold) {
    int cluster_no = 0;
    for (const auto& cluster_nodes : find_clusters(threshold)) {
        // find outer nodes of the cluster
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
        // find neighbours of each outer node
        for (uint64_t outer_node : outer_nodes) {
            outer_neighbours_map[outer_node] = {};
            // add all other outer nodes as neighbours
            for (uint64_t neighbour : outer_nodes) {
                if (outer_node == neighbour) {
                    continue;
                }
                Path path = find_path_astar(outer_node, neighbour, *this);
                if (!path.empty()) {
                    outer_neighbours_map[outer_node].insert({neighbour, path});
                }
            }
            // add all neighbours not from cluster
            for (const auto& [neighbour, path] : *get_neighbours(outer_node)) {
                if (nodes.at(neighbour).get_cluster_no() != cluster_no) {
                    outer_neighbours_map[outer_node].insert({neighbour, path});
                }
            }
        }
        clusters[cluster_no] = outer_neighbours_map;
        ++cluster_no;
    }
}
