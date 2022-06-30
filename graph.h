#ifndef HIERARCHICAL_PATHFINDING_GRAPH_H
#define HIERARCHICAL_PATHFINDING_GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include "types.h"
#include "path.h"
#include "cluster.h"

typedef std::unordered_set<std::pair<uint64, Path>> adj_nodes;
typedef std::unordered_map<uint64, adj_nodes> adj_list;
typedef std::unordered_map<uint64, Cluster> cluster_map;

class Graph {
private: node_map nodes;
private: adj_list neighbours;
private: cluster_map clusters;
// public: Graph(...);
public: void clusterize();
public: adj_nodes get_neighbours(uint64);
};

#endif //HIERARCHICAL_PATHFINDING_GRAPH_H
