project(cowblocks)
include(CMakePrintHelpers)

find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")

add_executable(cowblocks
 ${SOURCES}
)

cmake_print_variables(PROJECT_SOURCE_DIR)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/../source/include
        ${SDL2_INCLUDE_DIR}
        ${JPEG_INCLUDE_DIR}
)

target_link_libraries(cowblocks PUBLIC GLG3D G3D)
