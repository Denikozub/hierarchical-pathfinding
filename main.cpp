#include <iostream>
#include "graph.h"

int main()
{
    std::string path = "../tests/from-py.graphml";
    Graph graph = from_graphml(path);
    find_path_astar(1, 2, graph);

    return 0;
}