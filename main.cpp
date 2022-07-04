#include <iostream>
#include "graph.h"
#include "astar.h"

int main()
{
    std::string path = "../tests/from-py.graphml";
    Graph graph(path);
    find_path_astar(1, 2, graph);

    return 0;
}