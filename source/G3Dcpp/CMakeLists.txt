project(G3D)
include(CMakePrintHelpers)

find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL2 REQUIRED)

add_library(G3D STATIC
        AABox.cpp
        AnyVal.cpp
        BinaryFormat.cpp
        BinaryInput.cpp
        BinaryOutput.cpp
        Box.cpp
        Capsule.cpp
        CollisionDetection.cpp
        Color3.cpp
        Color3uint8.cpp
        Color4.cpp
        Color4uint8.cpp
        Cone.cpp
        ConvexPolyhedron.cpp
        CoordinateFrame.cpp
        Crypto.cpp
        Crypto_md5.cpp
        Cylinder.cpp
        debugAssert.cpp
        Discovery.cpp
        fileutils.cpp
        format.cpp
        g3derror.cpp
        g3dmath.cpp
        GCamera.cpp
        GImage.cpp
        GImage_bayer.cpp
        GImage_bmp.cpp
        GImage_jpeg.cpp
        GImage_png.cpp
        GImage_ppm.cpp
        GImage_tga.cpp
        GLight.cpp
        GThread.cpp
        license.cpp
        Line.cpp
        LineSegment.cpp
        Log.cpp
        Matrix3.cpp
        Matrix4.cpp
        MeshAlg.cpp
        MeshAlgAdjacency.cpp
        MeshAlgWeld.cpp
        MeshBuilder.cpp
        NetAddress.cpp
        NetworkDevice.cpp
        PhysicsFrame.cpp
        Plane.cpp
        prompt.cpp
        Quat.cpp
        Ray.cpp
        RegistryUtil.cpp
        Sphere.cpp
        Stopwatch.cpp
        stringutils.cpp
        System.cpp
        TextInput.cpp
        TextOutput.cpp
        Triangle.cpp
        Vector2.cpp
        Vector2int16.cpp
        Vector3.cpp
        Vector3int16.cpp
        Vector4.cpp
)

cmake_print_variables(PROJECT_SOURCE_DIR)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/../include
        ${SDL2_INCLUDE_DIR}
        ${JPEG_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/../imgui
)

if (WIN32)
    target_link_libraries(G3D PUBLIC IMGUI ${SDL2_LIBRARIES} ${JPEG_LIBRARIES} ${PNG_LIBRARIES} wsock32 ws2_32 version)
else()
    target_link_libraries(G3D PUBLIC IMGUI ${SDL2_LIBRARIES} ${JPEG_LIBRARIES} ${PNG_LIBRARIES})
endif()