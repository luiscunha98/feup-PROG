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
include external/gtest/googletest/CMakeFiles/gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/gtest/googletest/CMakeFiles/gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include external/gtest/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include external/gtest/googletest/CMakeFiles/gtest.dir/flags.make

external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: external/gtest/googletest/CMakeFiles/gtest.dir/flags.make
external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../external/gtest/googletest/src/gtest-all.cc
external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: external/gtest/googletest/CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o -MF CMakeFiles/gtest.dir/src/gtest-all.cc.o.d -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/luisfpc/CLionProjects/projeto_2/progp2/external/gtest/googletest/src/gtest-all.cc

external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luisfpc/CLionProjects/projeto_2/progp2/external/gtest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luisfpc/CLionProjects/projeto_2/progp2/external/gtest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: external/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: external/gtest/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: external/gtest/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtestd.a"
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/gtest/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a
.PHONY : external/gtest/googletest/CMakeFiles/gtest.dir/build

external/gtest/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : external/gtest/googletest/CMakeFiles/gtest.dir/clean

external/gtest/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luisfpc/CLionProjects/projeto_2/progp2 /home/luisfpc/CLionProjects/projeto_2/progp2/external/gtest/googletest /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest /home/luisfpc/CLionProjects/projeto_2/progp2/cmake-build-debug/external/gtest/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/gtest/googletest/CMakeFiles/gtest.dir/depend

