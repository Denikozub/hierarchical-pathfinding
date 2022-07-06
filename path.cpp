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

void Path::to_gpx(uint64_t start, const std::string &file_path, const node_map *all_node_map) const {
    FILE *gpx_file = fopen(file_path.c_str(), "w");
    if (gpx_file == nullptr) {
        throw std::runtime_error("Could not open gpx file");
    }
    fprintf(gpx_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(gpx_file, "<gpx\n"
                      "xmlns=\"http://www.topografix.com/GPX/1/1\"\n"
                      "creator=\"https://github.com/Denikozub/hierarchical-pathfinding\"\n"
                      "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
                      "xsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 "
                      "http://www.topografix.com/GPX/1/1/gpx.xsd\" version=\"1.1\">\n"
                      );
    fprintf(gpx_file, "\t<wpt lat=\"%f\" lon=\"%f\">\n\t\t<name>Start</name>\n\t</wpt>\n",
            all_node_map->at(start).get_lat(),
            all_node_map->at(start).get_lon());

    fprintf(gpx_file, "\t<wpt lat=\"%f\" lon=\"%f\">\n\t\t<name>Goal</name>\n\t</wpt>\n",
            all_node_map->at(*path.rbegin()).get_lat(),
            all_node_map->at(*path.rbegin()).get_lon());

    fprintf(gpx_file, "\t<trk>\n\t\t<name>%s</name>\n\t\t<trkseg>\n", "road");
    for (uint64_t node_id : this->path) {
        fprintf(gpx_file, "\t\t\t<trkpt lat=\"%f\" lon=\"%f\"></trkpt>\n",
                all_node_map->at(node_id).get_lat(),
                all_node_map->at(node_id).get_lon());
    }
    fprintf(gpx_file, "\t\t</trkseg>\n\t</trk>\n</gpx>\n");
}

size_t PathHash::operator()(const Path &p) const {
    if (p.path.empty()) {
        return 0;
    }
    return std::hash<double>()(p.weight) ^ (*p.path.begin() * *(p.path.end() - 1));
}
