# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/mike/Desktop/Hobby Project/glfw-learn"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug"

# Include any dependencies generated for this target.
include glew/CMakeFiles/glew.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glew/CMakeFiles/glew.dir/compiler_depend.make

# Include the progress variables for this target.
include glew/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include glew/CMakeFiles/glew.dir/flags.make

glew/CMakeFiles/glew.dir/__/__/src/glew.c.o: glew/CMakeFiles/glew.dir/flags.make
glew/CMakeFiles/glew.dir/__/__/src/glew.c.o: /Users/mike/Desktop/Hobby\ Project/glfw-learn/external/glew/src/glew.c
glew/CMakeFiles/glew.dir/__/__/src/glew.c.o: glew/CMakeFiles/glew.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/CMakeFiles/glew.dir/__/__/src/glew.c.o"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glew/CMakeFiles/glew.dir/__/__/src/glew.c.o -MF CMakeFiles/glew.dir/__/__/src/glew.c.o.d -o CMakeFiles/glew.dir/__/__/src/glew.c.o -c "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glew.c"

glew/CMakeFiles/glew.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/__/__/src/glew.c.i"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glew.c" > CMakeFiles/glew.dir/__/__/src/glew.c.i

glew/CMakeFiles/glew.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/__/__/src/glew.c.s"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glew.c" -o CMakeFiles/glew.dir/__/__/src/glew.c.s

# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/__/__/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

lib/libGLEWd.2.2.0.dylib: glew/CMakeFiles/glew.dir/__/__/src/glew.c.o
lib/libGLEWd.2.2.0.dylib: glew/CMakeFiles/glew.dir/build.make
lib/libGLEWd.2.2.0.dylib: glew/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../lib/libGLEWd.dylib"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -E cmake_symlink_library ../lib/libGLEWd.2.2.0.dylib ../lib/libGLEWd.2.2.dylib ../lib/libGLEWd.dylib

lib/libGLEWd.2.2.dylib: lib/libGLEWd.2.2.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEWd.2.2.dylib

lib/libGLEWd.dylib: lib/libGLEWd.2.2.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEWd.dylib

# Rule to build all files generated by this target.
glew/CMakeFiles/glew.dir/build: lib/libGLEWd.dylib
.PHONY : glew/CMakeFiles/glew.dir/build

glew/CMakeFiles/glew.dir/clean:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : glew/CMakeFiles/glew.dir/clean

glew/CMakeFiles/glew.dir/depend:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mike/Desktop/Hobby Project/glfw-learn" "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/build/cmake" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew/CMakeFiles/glew.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : glew/CMakeFiles/glew.dir/depend
