cmake_minimum_required(VERSION 3.25)
project(glfw_learn)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp
        src/Window/Window.cpp include/Window/Window.h
        src/Mesh/Mesh.cpp include/Mesh/Mesh.h
        src/Shader/Shader.cpp include/Shader/Shader.h
        src/Camera/Camera.cpp include/Camera/Camera.h include/Texture/stb_image.h src/Texture/Texture.cpp include/Texture/Texture.h src/Light/Light.cpp include/Light/Light.h)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/external/glew/include)

target_compile_definitions(${PROJECT_NAME} PRIVATE SHADER_PATH="${CMAKE_CURRENT_SOURCE_DIR}/graphics/shaders/")
target_compile_definitions(${PROJECT_NAME} PRIVATE TEXTURE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/graphics/textures/")


add_subdirectory(external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

add_subdirectory(external/glew/build/cmake ${CMAKE_CURRENT_BINARY_DIR}/glew)
target_link_libraries(${PROJECT_NAME} PRIVATE glew)

add_subdirectory(external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)

#[[
if (WIN32)
    file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/dlls GLEW_DLL_DESTINATION_NATIVE)
    file(COPY ${CMAKE_BINARY_DIR}/bin/glew32d.dll DESTINATION ${GLEW_DLL_DESTINATION_NATIVE})
    target_compile_definitions(${PROJECT_NAME} PRIVATE GLEW_DLL_PATH= "${GLEW_DLL_DESTINATION_NATIVE}/glew32d.dll")
endif ()
]]
