cmake_minimum_required(VERSION 3.25)
project(glfw_learn)

set(GAME glfw_learn)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(GLEW_STATIC)

add_executable(glfw_learn main.cpp)

add_subdirectory(external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${GAME} PRIVATE glfw)

add_subdirectory(external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${GAME} PRIVATE glad)

add_subdirectory(external/glew ${CMAKE_CURRENT_BINARY_DIR}/glew)
target_link_libraries(${GAME} PRIVATE glew)

