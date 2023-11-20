project(gfxmeter)

find_package(SDL2 REQUIRED)

add_executable(gfxmeter
        main.cpp
        measureVertexPerformance.cpp
        Report.cpp
        shaderVersions.cpp
        speed.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/source/include)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/source/include ${SDL2_INCLUDE_DIR}
)

target_link_libraries(gfxmeter PUBLIC ${SDL2_LIBRARIES} GLG3D G3D)