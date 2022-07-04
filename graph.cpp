#include <cstring>
#include "graph.h"

Graph from_graphml(const std::string& input_file) {
    pugi::xml_document document;
    if (!document.load_file(input_file.c_str())) {
        throw std::runtime_error("Could not load file");
    }
    Graph graph;
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
            graph.nodes.insert({id, Node(lat, lon)});
        } else {
            uint64_t source = xml_note.attribute("source").as_ullong();
            uint64_t target = xml_note.attribute("target").as_ullong();
            double weight = std::stod(xml_note.begin()->text().get());

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

const adj_nodes *Graph::get_neighbours(uint64_t id) const {
    if (nodes.at(id).has_cluster() && nodes.at(id).is_outer()) {
        uint64_t cluster_id = nodes.at(id).get_cluster_no();
        return clusters.at(cluster_id).get_outer_neighbours(id);
    }
    return &node_neighbours_map.at(id);
}

const Node* Graph::get_node(uint64_t id) const {
    return &nodes.at(id);
}
