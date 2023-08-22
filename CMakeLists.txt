cmake_minimum_required(VERSION 3.25)
project(glfw_learn)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/external/glew/include)

add_subdirectory(external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

add_subdirectory(external/glew/build/cmake ${CMAKE_CURRENT_BINARY_DIR}/glew)
target_link_libraries(${PROJECT_NAME} PRIVATE glew)

if (WIN32)
    file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/dlls GLEW_DLL_DESTINATION_NATIVE)
    file(COPY ${CMAKE_BINARY_DIR}/bin/glew32d.dll DESTINATION ${GLEW_DLL_DESTINATION_NATIVE})
    target_compile_definitions(${PROJECT_NAME} PRIVATE GLEW_DLL_PATH="${GLEW_DLL_DESTINATION_NATIVE}/glew32d.dll")
endif()
