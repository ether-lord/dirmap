cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(DirMap)

include_directories(src)
add_subdirectory(src)

add_compile_options(
  -fsanitize=address
  -fsanitize=undefined
  -fno-sanitize-recover=all
  -fsanitize=float-divide-by-zero
  -fsanitize=float-cast-overflow
  -fno-sanitize=null
  -fno-sanitize=alignment)
add_compile_options(-fsanitize=address, -lasan, -fsanitize=undefined)
add_link_options(-fsanitize=address, -fsanitize=undefined)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE dirmap)
