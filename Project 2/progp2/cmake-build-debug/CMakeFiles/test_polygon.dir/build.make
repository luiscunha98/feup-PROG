# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/178/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/178/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luisfpc/CLionProjects/projeto_2/progp2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_polygon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_polygon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_polygon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_polygon.dir/flags.make

CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o: CMakeFiles/test_polygon.dir/flags.make
CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o: ../test/test_polygon.cpp
CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o: CMakeFiles/test_polygon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o -MF CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o.d -o CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o -c /home/luisfpc/CLionProjects/projeto_2/progp2/test/test_polygon.cpp

CMakeFiles/test_polygon.dir/test/test_polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_polygon.dir/test/test_polygon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luisfpc/CLionProjects/projeto_2/progp2/test/test_polygon.cpp > CMakeFiles/test_polygon.dir/test/test_polygon.cpp.i

CMakeFiles/test_polygon.dir/test/test_polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_polygon.dir/test/test_polygon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luisfpc/CLionProjects/projeto_2/progp2/test/test_polygon.cpp -o CMakeFiles/test_polygon.dir/test/test_polygon.cpp.s

# Object files for target test_polygon
test_polygon_OBJECTS = \
"CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o"

# External object files for target test_polygon
test_polygon_EXTERNAL_OBJECTS =

test_polygon: CMakeFiles/test_polygon.dir/test/test_polygon.cpp.o
test_polygon: CMakeFiles/test_polygon.dir/build.make
test_polygon: libsvg.a
test_polygon: libtinyxml2.a
test_polygon: lib/libgtestd.a
test_polygon: lib/libgtest_maind.a
test_polygon: lib/libgtestd.a
test_polygon: CMakeFiles/test_polygon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_polygon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_polygon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_polygon.dir/build: test_polygon
.PHONY : CMakeFiles/test_polygon.dir/build

CMakeFiles/test_polygon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_polygon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_polygon.dir/clean

CMakeFiles/test_polygon.dir/depend:
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luisfpc/CLionProjects/projeto_2/progp2 /home/luisfpc/CLionProjects/projeto_2/progp2 /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/CMakeFiles/test_polygon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_polygon.dir/depend
