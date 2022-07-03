#include <cstring>
#include "graph.h"

Graph::Graph(const std::string &input_file) {
    this->nodes = node_map{};

    pugi::xml_document document;
    if (!document.load_file(input_file.c_str())) {
        //TODO: throw error if we don't parse input file?
        exit(1);
    }

    for (pugi::xml_node &xml_note: document.child("graphml").child("graph")) {
        if (strcmp(xml_note.name(), "node") == 0) {
            double lat = 0, lon = 0;
            for (pugi::xml_node &data: xml_note) {
                if (strcmp(data.attributes_begin()->value(), "lat") == 0) {
                    lat = std::stod(data.text().get());
                } else {
                    lon = std::stod(data.text().get());
                }
            }
            uint64_t id = xml_note.attribute("id").as_ullong();
            this->nodes.insert({id, Node(lat, lon)});
        } else {
            uint64_t source = xml_note.attribute("source").as_ullong();
            uint64_t target = xml_note.attribute("target").as_ullong();
            double weight = std::stod(xml_note.begin()->text().get());

            Path path = Path(&(this->nodes));
            path.add(target, weight);

            adj_list *neighbours_map = &(this->node_neighbours_map);
            if (neighbours_map->find(source) != neighbours_map->end()) {
                neighbours_map->operator[](source).insert({target, path});
            } else {
                neighbours_map->operator[](source) = adj_nodes{{target, path}};
            }
        }
    }
}

const adj_nodes *Graph::get_neighbours(uint64_t id) const {
    if (nodes.at(id).has_cluster() && nodes.at(id).is_outer()) {
        uint64_t cluster_id = nodes.at(id).get_cluster_no();
        return clusters.at(cluster_id).get_outer_neighbours(id);
    }
    return &node_neighbours_map.at(id);
}
