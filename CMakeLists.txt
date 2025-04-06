cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

# Find OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

#copy libs to build
file(COPY ${CMAKE_SOURCE_DIR}/lib DESTINATION ${CMAKE_BINARY_DIR})

# Add GLAD
add_library(glad glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include) 

# Create Executable
add_executable(OpenGLApp main.cpp)

# Link Libraries
target_link_libraries(OpenGLApp PRIVATE glad OpenGL::GL glfw)
target_include_directories(OpenGLApp PUBLIC ${CMAKE_SOURCE_DIR}/include) 

