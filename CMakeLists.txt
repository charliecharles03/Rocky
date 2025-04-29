cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# GLAD library
add_library(glad src/glad.c)

target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Copy 'lib' directory to build directory
file(COPY ${CMAKE_SOURCE_DIR}/lib DESTINATION ${CMAKE_BINARY_DIR})

# Executable
add_executable(OpenGLApp src/main.cpp)

# Link libraries to executable
target_link_libraries(OpenGLApp
    PRIVATE
        glad
        OpenGL::GL
        glfw
)

# Include directories for the executable
target_include_directories(OpenGLApp PUBLIC ${CMAKE_SOURCE_DIR}/include)

