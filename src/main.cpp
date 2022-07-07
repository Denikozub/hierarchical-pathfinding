#include <iostream>
#include "graph.h"

int main()
{
    std::string path = "../tests/helsinki.graphml";
    Graph graph = from_graphml(path);
    find_path_astar(2485472945, 297677064, graph, 100.).to_gpx(2485472945, "route.gpx", graph.get_nodes());
    // graph.clusterize(1);
    // std::cout << graph.cluster_count();
    // graph.export_nodes("nodes.csv");

    return 0;
}