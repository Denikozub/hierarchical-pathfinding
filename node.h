#ifndef HIERARCHICAL_PATHFINDING_NODE_H
#define HIERARCHICAL_PATHFINDING_NODE_H

class Node {
private:
    double lat, lon;
    int cluster_no {-1};
    bool is_outer_ {false};
public:
    Node(double, double);
    Node(const Node &);
    Node(Node&&);
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
