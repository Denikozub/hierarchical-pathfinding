#include <iostream>
#include "../src/graph.h"

int main()
{
    std::string path = "../tests/helsinki.graphml";
    Graph graph = from_graphml(path);
    graph.clusterize(0.1);
    std::cout << graph.cluster_count();
    find_path_astar(335032885, 5566659612, graph, 100.).to_gpx(335032885, "route1.gpx", graph.get_nodes());
    find_path_astar(335032885, 314039002, graph, 100.).to_gpx(335032885, "route2.gpx", graph.get_nodes());
    find_path_astar(1369465901, 5566659612, graph, 100.).to_gpx(1369465901, "route3.gpx", graph.get_nodes());
    find_path_astar(1369465901, 314039002, graph, 100.).to_gpx(1369465901, "route4.gpx", graph.get_nodes());

    return 0;
}