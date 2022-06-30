#include "path.h"

Path::Path(const node_map* nodes) : nodes(nodes) {}

void Path::add(uint64_t new_node, double new_weight) {
    path.insert(path.end(), new_node);
    weight += new_weight;
}

void Path::add(const Path& other) {
    path.insert(path.end(), other.path.begin(), other.path.end());
    weight += other.weight;
}

double Path::get_weight() const {
    return weight;
}
