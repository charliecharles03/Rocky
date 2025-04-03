cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add GLAD
add_library(glad glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include)  # Correct path

# Create Executable
add_executable(OpenGLApp main.cpp)

# Link Libraries
target_link_libraries(OpenGLApp PRIVATE glad OpenGL::GL)
target_include_directories(OpenGLApp PUBLIC ${CMAKE_SOURCE_DIR}/include)  # Make glad.h accessible

