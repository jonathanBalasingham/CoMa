# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/jon/Programs/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jon/Programs/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jon/CLionProjects/CoMa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jon/CLionProjects/CoMa/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CoMa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CoMa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CoMa.dir/flags.make

CMakeFiles/CoMa.dir/library.cpp.o: CMakeFiles/CoMa.dir/flags.make
CMakeFiles/CoMa.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jon/CLionProjects/CoMa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CoMa.dir/library.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CoMa.dir/library.cpp.o -c /home/jon/CLionProjects/CoMa/library.cpp

CMakeFiles/CoMa.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CoMa.dir/library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jon/CLionProjects/CoMa/library.cpp > CMakeFiles/CoMa.dir/library.cpp.i

CMakeFiles/CoMa.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CoMa.dir/library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jon/CLionProjects/CoMa/library.cpp -o CMakeFiles/CoMa.dir/library.cpp.s

# Object files for target CoMa
CoMa_OBJECTS = \
"CMakeFiles/CoMa.dir/library.cpp.o"

# External object files for target CoMa
CoMa_EXTERNAL_OBJECTS =

libCoMa.a: CMakeFiles/CoMa.dir/library.cpp.o
libCoMa.a: CMakeFiles/CoMa.dir/build.make
libCoMa.a: CMakeFiles/CoMa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jon/CLionProjects/CoMa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCoMa.a"
	$(CMAKE_COMMAND) -P CMakeFiles/CoMa.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CoMa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CoMa.dir/build: libCoMa.a

.PHONY : CMakeFiles/CoMa.dir/build

CMakeFiles/CoMa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CoMa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CoMa.dir/clean

CMakeFiles/CoMa.dir/depend:
	cd /home/jon/CLionProjects/CoMa/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jon/CLionProjects/CoMa /home/jon/CLionProjects/CoMa /home/jon/CLionProjects/CoMa/cmake-build-debug /home/jon/CLionProjects/CoMa/cmake-build-debug /home/jon/CLionProjects/CoMa/cmake-build-debug/CMakeFiles/CoMa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CoMa.dir/depend
