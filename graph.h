#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include "types.h"
#include "path.h"

class Graph;
Graph from_graphml(const std::string&);
Path find_path_astar(uint64_t start, uint64_t goal, const Graph&, double heuristic_multiplier = 10);

class Graph {
private:
    node_map nodes = node_map{};
    adj_list node_neighbours_map = adj_list{};
    std::unordered_map<int, adj_list> clusters {};
    friend Graph from_graphml(const std::string&);
    friend Path find_path_astar(uint64_t, uint64_t, const Graph&, double);
    std::unordered_set<std::unordered_set<uint64_t>> find_clusters(double);
public:
    void clusterize(double threshold);
    const adj_nodes* get_neighbours(uint64_t) const;
    const Node* get_node(uint64_t) const;
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
