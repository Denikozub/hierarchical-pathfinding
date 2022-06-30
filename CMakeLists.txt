cmake_minimum_required(VERSION 3.22)
project(hierarchical_pathfinding CXX)

set(CMAKE_CXX_STANDARD 20)



add_executable(hierarchical_pathfinding
        node.h types.h cluster.h path.h graph.h unclustered_graph.h clustered_graph.h)

set_target_properties(hierarchical_pathfinding PROPERTIES LINKER_LANGUAGE CXX)
