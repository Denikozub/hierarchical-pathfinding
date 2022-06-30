#ifndef HIERARCHICAL_PATHFINDING_CLUSTER_H
#define HIERARCHICAL_PATHFINDING_CLUSTER_H

#include "types.h"
#include "path.h"
#include "graph.h"

class Cluster {
public: Cluster(const Graph&);
public: Cluster(const Cluster&);
public: Cluster(Cluster&&);
public: void compute();
public: id_set get_outer();
public: double get_outer_dist(uint64, uint64);
public: Path get_outer_path(uint64, uint64);
};

#endif //HIERARCHICAL_PATHFINDING_CLUSTER_H
