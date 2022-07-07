#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "path.h"
#include "node.h"

class PairHash;
typedef std::unordered_set<std::pair<uint64_t, Path>, PairHash> adj_nodes;
typedef std::unordered_map<uint64_t, adj_nodes> adj_list;

class PairHash {
public: size_t operator()(const std::pair<uint64_t, Path> &p) const {
        return p.first;
    }
};

class Graph;
Graph from_graphml(const std::string&);
Path find_path_astar(uint64_t start, uint64_t goal, const Graph&, double heuristic_multiplier = 100);

class Graph {
private:
    node_map nodes = node_map{};
    adj_list node_neighbours_map = adj_list{};
    std::unordered_map<int, adj_list> clusters {};
    friend Graph from_graphml(const std::string&);
    friend Path find_path_astar(uint64_t, uint64_t, const Graph&, double);
    std::vector<std::unordered_set<uint64_t>> find_clusters(double);
public:
    void clusterize(double threshold);
    size_t cluster_count() const;
    const adj_nodes* get_neighbours(uint64_t, bool use_clusters = true) const;
    const Node* get_node(uint64_t) const;
    const node_map* get_nodes() const;
    void export_nodes(const std::string&) const;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
