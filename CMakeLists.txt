cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

# Find OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)


include_directories(
    ${CMAKE_SOURCE_DIR}/include/imgui
    ${CMAKE_SOURCE_DIR}/include/imgui/backends
)


add_library(imgui
    include/imgui/imgui.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_tables.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/backends/imgui_impl_glfw.cpp
    include/imgui/backends/imgui_impl_opengl3.cpp
)


#copy libs to build
file(COPY ${CMAKE_SOURCE_DIR}/lib DESTINATION ${CMAKE_BINARY_DIR})

# Add GLAD
add_library(glad glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include) 

# Create Executable
add_executable(OpenGLApp main.cpp)

# Link Libraries
target_link_libraries(OpenGLApp PRIVATE imgui glad OpenGL::GL glfw)
target_include_directories(OpenGLApp PUBLIC ${CMAKE_SOURCE_DIR}/include) 

