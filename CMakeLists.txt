cmake_minimum_required(VERSION 3.16)
project(hierarchical_pathfinding CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(pugixml)

add_executable(hierarchical_pathfinding
        node.h path.h graph.h main.cpp path.cpp node.cpp cluster.cpp graph.cpp astar.cpp)

set_target_properties(hierarchical_pathfinding PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(hierarchical_pathfinding pugixml)
