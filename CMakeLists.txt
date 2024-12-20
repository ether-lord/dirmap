cmake_minimum_required(VERSION 3.14)

project(DirMap)

include_directories(src)
add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE dirmap)