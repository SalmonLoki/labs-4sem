# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/krovlya/programs/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/krovlya/programs/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/flags.make

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/flags.make
CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o -c "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/main.cpp"

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/main.cpp" > CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.i

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/main.cpp" -o CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.s

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.requires

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.provides: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/build.make CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.provides

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.provides.build: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o


# Object files for target BIGDATA_SIMPLICITY_CHECK
BIGDATA_SIMPLICITY_CHECK_OBJECTS = \
"CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o"

# External object files for target BIGDATA_SIMPLICITY_CHECK
BIGDATA_SIMPLICITY_CHECK_EXTERNAL_OBJECTS =

BIGDATA_SIMPLICITY_CHECK: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o
BIGDATA_SIMPLICITY_CHECK: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/build.make
BIGDATA_SIMPLICITY_CHECK: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BIGDATA_SIMPLICITY_CHECK"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/build: BIGDATA_SIMPLICITY_CHECK

.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/build

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/requires: CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/main.cpp.o.requires

.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/requires

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/clean

CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/depend:
	cd "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK" "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK" "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug" "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug" "/home/krovlya/CLionProjects/Математика, криптография/BIGDATA_SIMPLICITY_CHECK/cmake-build-debug/CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BIGDATA_SIMPLICITY_CHECK.dir/depend

