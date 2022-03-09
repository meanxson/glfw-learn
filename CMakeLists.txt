cmake_minimum_required(VERSION 3.20)
project(glfw_learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(glfw_learn main.cpp)

add_subdirectory(external/glfw ${CMAKE_BINARY_DIR}/glfw)
target_link_libraries(glfw_learn PRIVATE glfw)