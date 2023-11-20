cmake_minimum_required(VERSION 3.26)
project(Bluff3D)

add_subdirectory(source)
add_subdirectory(game)

# provide only x86 builds due to G3D not compiling on 64 bit
set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_C_FLAGS "-m32")