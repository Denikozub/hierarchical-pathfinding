#include <iostream>
#include "graph.h"

int main()
{
    std::string path = "../tests/from-py.graphml";
    Graph graph = from_graphml(path);
    find_path_astar(1, 2, graph);
    graph.clusterize(1);
    find_path_astar(1, 2, graph).to_gpx(1, "test.gpx", graph.get_nodes());

    return 0;
}