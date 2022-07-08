#include <iostream>
#include "../src/graph.h"

int main()
{
    std::string path = "../tests/helsinki.graphml";
    Graph graph = from_graphml(path);
    graph.clusterize(0.05);
    std::cout << graph.cluster_count();
    find_path_astar(335032885, 5566659612, graph, true, 100.).to_gpx(335032885, "route1.gpx", graph.get_nodes());
    find_path_astar(335032885, 314039002, graph, true, 100.).to_gpx(335032885, "route2.gpx", graph.get_nodes());
    find_path_astar(1369465901, 5566659612, graph, true, 100.).to_gpx(1369465901, "route3.gpx", graph.get_nodes());
    find_path_astar(1369465901, 314039002, graph, true, 100.).to_gpx(1369465901, "route4.gpx", graph.get_nodes());

    return 0;
}