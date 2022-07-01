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

bool Path::empty() const {
    return path.empty();
}

size_t PathHash::operator()(const Path &p) const {
    return std::hash<double>()(p.weight) ^ (*p.path.begin() * *p.path.end());
}
