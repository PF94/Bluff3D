project(Game)
include(CMakePrintHelpers)

find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL REQUIRED)

add_executable(Game
        Demo.cpp
        Demo.h
        main.cpp
        interface.cpp
        interface.h
)

cmake_print_variables(PROJECT_SOURCE_DIR)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/../source/include
        ${SDL_INCLUDE_DIR}
        ${JPEG_INCLUDE_DIR}
)

target_link_libraries(Game PUBLIC GLG3D G3D)