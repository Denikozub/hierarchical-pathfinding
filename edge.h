#ifndef HIERARCHICAL_PATHFINDING_EDGE_H
#define HIERARCHICAL_PATHFINDING_EDGE_H

#include "types.h"

class Edge {
private:
    uint64 start, end;
    double weight;
public:
    Edge(uint64, uint64, double);
    Edge(const Edge&);
    Edge(Edge&&);
    double get_weight();
    void set_weight(double);
};

#endif //HIERARCHICAL_PATHFINDING_EDGE_H
