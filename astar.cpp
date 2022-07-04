#include <cmath>
#include <queue>
#include <unordered_map>
#include "astar.h"
#include "node.h"

static double haversine(const Node& node1, const Node& node2) {
    double lat1 = node1.get_lat(), lon1 = node1.get_lon(), \
           lat2 = node2.get_lat(), lon2 = node2.get_lon();
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    return 6371 * 2 * asin(sqrt(a));
}

static double heuristic(const Node& node1, const Node& node2, double heuristic_multiplier) {
    return haversine(node1, node2) * heuristic_multiplier;
}

typedef std::pair<uint64_t, double> Id_value;

Path find_path_astar(uint64_t start, uint64_t goal, const Graph& graph, double heuristic_multiplier) {
    auto cmp = [](const Id_value& left, const Id_value& right) { return left.second < right.second; };
    std::priority_queue<Id_value, std::vector<Id_value>, decltype(cmp)> frontier(cmp);
    frontier.push({start, 0});

    std::unordered_map<uint64_t, std::pair<uint64_t, Path>> came_from;
    came_from[start] = {start, Path()};
    std::unordered_map<uint64_t, double> cost_so_far;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        uint64_t current = frontier.top().first;
        if (current == goal) {
            break;
        }
        for (const auto& [neighbour, path] : *graph.get_neighbours(current)) {
            double new_cost = cost_so_far.at(current) + path.get_weight();
            if (cost_so_far.count(neighbour) == 0 || new_cost < cost_so_far.at(neighbour)) {
                cost_so_far[neighbour] = new_cost;
                double priority = new_cost +
                                  heuristic(*graph.get_node(goal), *graph.get_node(neighbour), heuristic_multiplier);
                frontier.push({neighbour, priority});
                came_from[neighbour] = {current, path};
            }
        }
    }

    // retrace (do not add start node)
    Path path;
    uint64_t current = goal;
    while (current != start) {
        if (came_from.count(current) == 0) {
            throw std::runtime_error("No path found");
        }
        path.add_reversed(came_from.at(current).second);
        current = came_from.at(current).first;
    }
    path.reverse();
    return path;
}