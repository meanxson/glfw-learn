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
include glew/CMakeFiles/glewinfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glew/CMakeFiles/glewinfo.dir/compiler_depend.make

# Include the progress variables for this target.
include glew/CMakeFiles/glewinfo.dir/progress.make

# Include the compile flags for this target's objects.
include glew/CMakeFiles/glewinfo.dir/flags.make

glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o: glew/CMakeFiles/glewinfo.dir/flags.make
glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o: /Users/mike/Desktop/Hobby\ Project/glfw-learn/external/glew/src/glewinfo.c
glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o: glew/CMakeFiles/glewinfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o -MF CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o.d -o CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o -c "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glewinfo.c"

glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glewinfo.c" > CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i

glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/src/glewinfo.c" -o CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s

# Object files for target glewinfo
glewinfo_OBJECTS = \
"CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o"

# External object files for target glewinfo
glewinfo_EXTERNAL_OBJECTS =

bin/glewinfo: glew/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.o
bin/glewinfo: glew/CMakeFiles/glewinfo.dir/build.make
bin/glewinfo: lib/libGLEWd.a
bin/glewinfo: glew/CMakeFiles/glewinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/glewinfo"
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glewinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glew/CMakeFiles/glewinfo.dir/build: bin/glewinfo
.PHONY : glew/CMakeFiles/glewinfo.dir/build

glew/CMakeFiles/glewinfo.dir/clean:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" && $(CMAKE_COMMAND) -P CMakeFiles/glewinfo.dir/cmake_clean.cmake
.PHONY : glew/CMakeFiles/glewinfo.dir/clean

glew/CMakeFiles/glewinfo.dir/depend:
	cd "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mike/Desktop/Hobby Project/glfw-learn" "/Users/mike/Desktop/Hobby Project/glfw-learn/external/glew/build/cmake" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew" "/Users/mike/Desktop/Hobby Project/glfw-learn/cmake-build-debug/glew/CMakeFiles/glewinfo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : glew/CMakeFiles/glewinfo.dir/depend

