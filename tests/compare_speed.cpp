#include <iostream>
#include <chrono>
#include <set>
#include "../src/graph.h"

int main()
{
    std::string path = "../tests/helsinki.graphml";
    Graph graph_unclusterized = from_graphml(path);
    Graph graph_clusterized = from_graphml(path);
    graph_clusterized.clusterize(0.05);

    std::set<uint64_t> node_samples = {248185607, 264013729, 288883177, 299268444, 299268999, 311039986, 314016352,
                                       314765500, 315280752, 318600213, 404746944, 404759611, 409472656, 581077362,
                                       581077421, 581082152, 583242720, 760466573, 945714784, 946493550, 1003245724,
                                       1012904572, 1015008193, 1319789488, 1369465775, 1371624181, 1371624184,
                                       1420465681, 1677741877, 1724492938, 1994501368, 1994501372, 2403921114,
                                       2485472897, 3139880045, 3217980943, 4435014118, 4447421089, 4733960688,
                                       5339503331, 5339503334, 5566659648, 5566659694, 5566659812, 5566659842,
                                       5759395541, 6057674016, 6061855680, 6062070299, 6062070327};

    std::chrono::steady_clock::time_point begin, end;
    begin = std::chrono::steady_clock::now();
    for (uint64_t start : node_samples) {
        for (uint64_t goal : node_samples) {
            find_path_astar(start, goal, graph_unclusterized);
        }
    }
    end = std::chrono::steady_clock::now();
    std::cout << "Unclusterized time = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " ms" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (uint64_t start : node_samples) {
        for (uint64_t goal : node_samples) {
            find_path_astar(start, goal, graph_clusterized);
        }
    }
    end = std::chrono::steady_clock::now();
    std::cout << "Unclusterized time = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " ms" << std::endl;

    return 0;
}
