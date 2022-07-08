#include <queue>
#include <unordered_map>
#include "graph.h"
#include "haversine.h"

typedef std::pair<uint64_t, double> Id_value;

static double heuristic(const Node& node1, const Node& node2, double heuristic_multiplier) {
    return haversine(node1, node2) * 1000 * heuristic_multiplier;
}

static Path retrace(uint64_t start, uint64_t goal, std::unordered_map<uint64_t, std::pair<uint64_t, Path>>&& came_from) {
    Path path;
    uint64_t current = goal;
    while (current != start) {
        if (came_from.count(current) == 0) {
            return {};
        }
        path.add_reversed(std::move(came_from.at(current).second));
        current = came_from.at(current).first;
    }
    path.reverse();
    return path;
}

Path find_path_astar(uint64_t start, uint64_t goal, const Graph& graph, bool use_clusters, double heuristic_multiplier) {
    auto cmp = [](const Id_value& left, const Id_value& right) { return left.second > right.second; };
    std::priority_queue<Id_value, std::vector<Id_value>, decltype(cmp)> frontier(cmp);
    frontier.push({start, 0});
    int goal_cluster = graph.nodes.at(goal).get_cluster_no();

    std::unordered_map<uint64_t, std::pair<uint64_t, Path>> came_from;
    came_from[start] = {start, Path()};
    std::unordered_map<uint64_t, double> cost_so_far;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        uint64_t current = frontier.top().first;
        frontier.pop();
        if (current == goal) {
            break;
        }
        use_clusters = use_clusters && goal_cluster != graph.nodes.at(current).get_cluster_no();
        for (const auto& [neighbour, path] : *graph.get_neighbours(current, use_clusters)) {
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
    return retrace(start, goal, std::move(came_from));
}
