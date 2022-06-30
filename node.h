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
    Node(double, double);
    Node(double&&, double&&);
    [[nodiscard]] double get_lat() const;
    void set_lat(double);
    [[nodiscard]] double get_lon() const;
    void set_lon(double);
    [[nodiscard]] int get_cluster_no() const;
    void set_cluster_no(int);
    [[nodiscard]] bool has_cluster() const;
    void set_outer(bool);
    [[nodiscard]] bool is_outer() const;
};

#endif //HIERARCHICAL_PATHFINDING_NODE_H
