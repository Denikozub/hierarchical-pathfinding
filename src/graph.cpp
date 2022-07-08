#include <cstring>
#include "graph.h"
#include "pugixml.hpp"

Graph from_graphml(const std::string& input_file) {
    pugi::xml_document document;
    if (!document.load_file(input_file.c_str())) {
        throw std::runtime_error("Could not load file");
    }

    std::string lon_tag, lat_tag, length_tag;
    for (pugi::xml_node &xml_attr: document.child("graphml")) {
        std::string attr_name = xml_attr.attribute("attr.name").value();
        std::string attr_id = xml_attr.attribute("id").value();
        if (attr_name == "x") {
            lon_tag = attr_id;
        } else if (attr_name == "y") {
            lat_tag = attr_id;
        } else if (attr_name == "length") {
            length_tag = attr_id;
        }
        if (!lat_tag.empty() && !lon_tag.empty()) {
            break;
        }
    }

    Graph graph;
    for (pugi::xml_node &xml_note: document.child("graphml").child("graph")) {
        if (strcmp(xml_note.name(), "node") == 0) {
            double lat = 0, lon = 0;
            bool lat_written = false, lon_written = false;
            for (pugi::xml_node &data: xml_note) {
                const char *attr_value = data.attribute("key").value();
                if (strcmp(attr_value, lat_tag.c_str()) == 0) {
                    lat = data.text().as_double();
                    lat_written = true;
                } else if (strcmp(attr_value, lon_tag.c_str()) == 0) {
                    lon = data.text().as_double();
                    lon_written = true;
                }
                if (lat_written && lon_written) {
                    break;
                }
            }
            uint64_t id = xml_note.attribute("id").as_ullong();
            graph.nodes.insert({id, Node(lat, lon)});
        } else {
            uint64_t source = xml_note.attribute("source").as_ullong();
            uint64_t target = xml_note.attribute("target").as_ullong();
            double weight = 0;
            for (pugi::xml_node &data: xml_note) {
                const char *attr_value = data.attribute("key").value();
                if (strcmp(attr_value, length_tag.c_str()) == 0) {
                    weight = data.text().as_double();
                    break;
                }
            }

            Path path = Path();
            path.add(target, weight);

            if (graph.node_neighbours_map.find(source) != graph.node_neighbours_map.end()) {
                graph.node_neighbours_map[source].insert({target, path});
            } else {
                graph.node_neighbours_map[source] = adj_nodes{{target, path}};
            }
        }
    }
    return graph;
}

void Graph::export_nodes(const std::string& file_path) const {
    FILE *nodes_file = fopen(file_path.c_str(), "w");
    if (nodes_file == nullptr) {
        throw std::runtime_error("Could not open nodes file");
    }
    fprintf(nodes_file, "id,lat,lon,cluster_no,is_outer\n");
    for (const auto& [id, node] : this->nodes) {
        fprintf(nodes_file, "%llu,%f,%f,%d,%d\n", id, node.get_lat(),
                node.get_lon(), node.get_cluster_no(), int(node.is_outer()));
    }
}

size_t Graph::cluster_count() const {
    return this->clusters.size();
}

const adj_nodes *Graph::get_neighbours(uint64_t id, bool use_clusters) const {
    if (use_clusters && this->nodes.at(id).has_cluster() && this->nodes.at(id).is_outer()) {
        int cluster_id = this->nodes.at(id).get_cluster_no();
        return &this->clusters.at(cluster_id).at(id);
    }
    return &this->node_neighbours_map.at(id);
}

const Node* Graph::get_node(uint64_t id) const {
    return &this->nodes.at(id);
}

const node_map* Graph::get_nodes() const {
    return &this->nodes;
}
