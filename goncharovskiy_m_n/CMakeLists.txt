cmake_minimum_required(VERSION 3.14)
include_directories(.)

#add_subdirectory(geom)
#add_executable (cat-n-mouse-1 cat-n-mouse(1).cpp)
#target_link_libraries(cat-n-mouse-1 geom)
#add_executable (modeling modeling.cpp)
#target_link_libraries(modeling geom)

add_subdirectory(rational_lib)
add_executable (test test.cpp)
target_link_libraries(test rational_lib)
