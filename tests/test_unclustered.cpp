#include "../src/graph.h"

int main()
{
    std::string path = "helsinki.graphml";
    Graph graph = from_graphml(path);
    find_path_astar(2485472945, 297677064, graph, 100.).to_gpx(2485472945, "route_unclustered.gpx", graph.get_nodes());

    return 0;
}