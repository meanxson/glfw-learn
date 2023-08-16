cmake_minimum_required(VERSION 3.25)

project(glew)

add_library(glew STATIC include/GL/glew.h src/glew.c)

target_include_directories(glew PUBLIC include)