#ifndef HIERARCHICAL_PATHFINDING_NODE_H
#define HIERARCHICAL_PATHFINDING_NODE_H

#include <unordered_map>
#include <cstdint>

class Node;
typedef std::unordered_map<uint64_t, Node> node_map;

class Node {
private:
    double lat, lon;
    int cluster_no {-1};
    bool is_outer_ {false};
public:
    Node(double lat, double lon);
    Node(double&& lat, double&& lon);
    double get_lat() const;
    void set_lat(double);
    double get_lon() const;
    void set_lon(double);
    int get_cluster_no() const;
    void set_cluster_no(int);
    bool has_cluster() const;
    void set_outer(bool);
    bool is_outer() const;
    void reset_cluster_data();
};

#endif //HIERARCHICAL_PATHFINDING_NODE_H
