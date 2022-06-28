#ifndef HIERARCHICAL_PATHFINDING_NODE_H
#define HIERARCHICAL_PATHFINDING_NODE_H

#include "types.h"

class Node {
private:
    uint64 id;
    double lat, lon;
    int cluster_no;
public:
    uint64 get_id();
    void set_id(uint64);
    double get_lat();
    void set_lat(double);
    double get_lon();
    void set_lon(double);
    int get_cluster_no();
    void set_cluster_no(int);
};

#endif //HIERARCHICAL_PATHFINDING_NODE_H
