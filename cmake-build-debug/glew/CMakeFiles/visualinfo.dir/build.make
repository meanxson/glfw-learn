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
include glew/CMakeFiles/visualinfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glew/CMakeFiles/visualinfo.dir/compiler_depend.make

# Include the progress variables for this target.
include glew/CMakeFiles/visualinfo.dir/progress.make

# Include the compile flags for this target's objects.
include glew/CMakeFiles/visualinfo.dir/flags.make

glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o: glew/CMakeFiles/visualinfo.dir/flags.make
glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o: /Users/mike/Desktop/Hobby\ Project/glfw-learn/external/glew/src/visualinfo.c
glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o: glew/CMakeFiles/visualinfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o -MF CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o.d -o CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o -c "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/visualinfo.c"

glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.i"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/visualinfo.c" > CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.i

glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.s"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/visualinfo.c" -o CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.s

# Object files for target visualinfo
visualinfo_OBJECTS = \
"CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o"

# External object files for target visualinfo
visualinfo_EXTERNAL_OBJECTS =

bin/visualinfo: glew/CMakeFiles/visualinfo.dir/__/__/src/visualinfo.c.o
bin/visualinfo: glew/CMakeFiles/visualinfo.dir/build.make
bin/visualinfo: lib/libGLEWd.a
bin/visualinfo: glew/CMakeFiles/visualinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/visualinfo"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/visualinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glew/CMakeFiles/visualinfo.dir/build: bin/visualinfo
.PHONY : glew/CMakeFiles/visualinfo.dir/build

glew/CMakeFiles/visualinfo.dir/clean:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -P CMakeFiles/visualinfo.dir/cmake_clean.cmake
.PHONY : glew/CMakeFiles/visualinfo.dir/clean

glew/CMakeFiles/visualinfo.dir/depend:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mike/Desktop/Hobby Project/glfw-learn" "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/build/cmake" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew/CMakeFiles/visualinfo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : glew/CMakeFiles/visualinfo.dir/depend
