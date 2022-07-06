cmake_minimum_required(VERSION 3.16)
project(hierarchical_pathfinding CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/pugixml)

add_executable(hierarchical_pathfinding
        src/node.h src/path.h src/graph.h src/main.cpp src/path.cpp src/node.cpp src/cluster.cpp src/graph.cpp src/astar.cpp src/haversine.h src/haversine.cpp)

set_target_properties(hierarchical_pathfinding PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(hierarchical_pathfinding src/pugixml)
