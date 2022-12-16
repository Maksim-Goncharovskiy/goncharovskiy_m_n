cmake_minimum_required(VERSION 3.14)
include_directories(.)

add_subdirectory(geom)

add_executable (modeling modeling.cpp)
target_link_libraries(modeling geom)
