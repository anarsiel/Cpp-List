# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/blagoi/Documents/year2018-list-testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/blagoi/Documents/year2018-list-testing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/counted.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/counted.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/counted.dir/flags.make

CMakeFiles/counted.dir/counted.cpp.o: CMakeFiles/counted.dir/flags.make
CMakeFiles/counted.dir/counted.cpp.o: ../counted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/blagoi/Documents/year2018-list-testing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/counted.dir/counted.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/counted.dir/counted.cpp.o -c /home/blagoi/Documents/year2018-list-testing/counted.cpp

CMakeFiles/counted.dir/counted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/counted.dir/counted.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blagoi/Documents/year2018-list-testing/counted.cpp > CMakeFiles/counted.dir/counted.cpp.i

CMakeFiles/counted.dir/counted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/counted.dir/counted.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blagoi/Documents/year2018-list-testing/counted.cpp -o CMakeFiles/counted.dir/counted.cpp.s

CMakeFiles/counted.dir/fault_injection.cpp.o: CMakeFiles/counted.dir/flags.make
CMakeFiles/counted.dir/fault_injection.cpp.o: ../fault_injection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/blagoi/Documents/year2018-list-testing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/counted.dir/fault_injection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/counted.dir/fault_injection.cpp.o -c /home/blagoi/Documents/year2018-list-testing/fault_injection.cpp

CMakeFiles/counted.dir/fault_injection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/counted.dir/fault_injection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blagoi/Documents/year2018-list-testing/fault_injection.cpp > CMakeFiles/counted.dir/fault_injection.cpp.i

CMakeFiles/counted.dir/fault_injection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/counted.dir/fault_injection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blagoi/Documents/year2018-list-testing/fault_injection.cpp -o CMakeFiles/counted.dir/fault_injection.cpp.s

# Object files for target counted
counted_OBJECTS = \
"CMakeFiles/counted.dir/counted.cpp.o" \
"CMakeFiles/counted.dir/fault_injection.cpp.o"

# External object files for target counted
counted_EXTERNAL_OBJECTS =

libcounted.a: CMakeFiles/counted.dir/counted.cpp.o
libcounted.a: CMakeFiles/counted.dir/fault_injection.cpp.o
libcounted.a: CMakeFiles/counted.dir/build.make
libcounted.a: CMakeFiles/counted.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/blagoi/Documents/year2018-list-testing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libcounted.a"
	$(CMAKE_COMMAND) -P CMakeFiles/counted.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/counted.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/counted.dir/build: libcounted.a

.PHONY : CMakeFiles/counted.dir/build

CMakeFiles/counted.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/counted.dir/cmake_clean.cmake
.PHONY : CMakeFiles/counted.dir/clean

CMakeFiles/counted.dir/depend:
	cd /home/blagoi/Documents/year2018-list-testing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/blagoi/Documents/year2018-list-testing /home/blagoi/Documents/year2018-list-testing /home/blagoi/Documents/year2018-list-testing/cmake-build-debug /home/blagoi/Documents/year2018-list-testing/cmake-build-debug /home/blagoi/Documents/year2018-list-testing/cmake-build-debug/CMakeFiles/counted.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/counted.dir/depend

