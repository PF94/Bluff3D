project(GLG3D)
include(CMakePrintHelpers)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(GLG3D STATIC
        DDSTexture.cpp
        directinput8.h
        Draw.cpp
        DXCaps.cpp
        edgeFeatures.cpp
        Framebuffer.cpp
        G3DGameUnits.cpp
        GApp.cpp
        getOpenGLState.cpp
        GFont.cpp
        glcalls.cpp
        GLCaps.cpp
        glenumtostring.cpp
        GModule.cpp
        GPUProgram.cpp
        GWindow.cpp
        IFSModel.cpp
        LightingParameters.cpp
        ManualCameraController.cpp
        MD2Model.cpp
        MD2Model_load.cpp
        Milestone.cpp
        PixelProgram.cpp
        PosedModel.cpp
        Renderbuffer.cpp
        RenderDevice.cpp
        SDLWindow.cpp
        Shader.cpp
        shadowVolume.cpp
        Shape.cpp
        Sky.cpp
        tesselate.cpp
        Texture.cpp
        TextureFormat.cpp
        TextureManager.cpp
        UserInput.cpp
        VAR.cpp
        VARArea.cpp
        VertexProgram.cpp
        Win32Window.cpp
)

cmake_print_variables(PROJECT_SOURCE_DIR)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/../include ${SDL2_INCLUDE_DIR}
)

target_link_libraries(GLG3D PUBLIC ${SDL2_LIBRARIES} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})