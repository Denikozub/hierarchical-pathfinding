#include <algorithm>
#include "path.h"

void Path::add(uint64_t new_node, double new_weight) {
    path.insert(path.end(), new_node);
    weight += new_weight;
}

void Path::add(const Path& other) {
    path.insert(path.end(), other.path.begin(), other.path.end());
    weight += other.weight;
}

void Path::add(Path&& other) {
    path.insert(path.end(), other.path.begin(), other.path.end());
    weight += other.weight;
}

void Path::add_reversed(const Path& other) {
    path.insert(path.end(), other.path.rbegin(), other.path.rend());
    weight += other.weight;
}

void Path::add_reversed(Path&& other) {
    path.insert(path.end(), other.path.rbegin(), other.path.rend());
    weight += other.weight;
}

double Path::get_weight() const {
    return weight;
}

bool Path::empty() const {
    return path.empty();
}

void Path::reverse() {
    std::reverse(path.begin(), path.end());
}

bool Path::operator==(const Path &other) const {
    return this->path == other.path;
}

size_t PathHash::operator()(const Path &p) const {
    if (p.path.empty()) {
        return 0;
    }
    return std::hash<double>()(p.weight) ^ (*p.path.begin() * *(p.path.end() - 1));
}
