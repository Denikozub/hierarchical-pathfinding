#ifndef HIERARCHICAL_PATHFINDING_NODE_H
#define HIERARCHICAL_PATHFINDING_NODE_H

#include <unordered_map>
#include "types.h"

class Node;
typedef std::unordered_map<uint64, Node> node_map;

class Node {
private:
    double lat, lon;
    int cluster_no {-1};
    bool is_outer_ {false};
public:
    Node(double, double);
    Node(double&&, double&&);
    double get_lat();
    void set_lat(double);
    double get_lon();
    void set_lon(double);
    int get_cluster_no();
    void set_cluster_no(int);
    bool has_cluster();
    void set_outer(bool);
    bool is_outer();
};

#endif //HIERARCHICAL_PATHFINDING_NODE_H
