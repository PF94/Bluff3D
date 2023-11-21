cmake_minimum_required(VERSION 3.26)
project(Bluff3D)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")

add_subdirectory(source)
add_subdirectory(game)