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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ousuke/cubeev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ousuke/cubeev/build

# Include any dependencies generated for this target.
include CMakeFiles/cubeev.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cubeev.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cubeev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cubeev.dir/flags.make

CMakeFiles/cubeev.dir/main.cpp.o: CMakeFiles/cubeev.dir/flags.make
CMakeFiles/cubeev.dir/main.cpp.o: ../main.cpp
CMakeFiles/cubeev.dir/main.cpp.o: CMakeFiles/cubeev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ousuke/cubeev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cubeev.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cubeev.dir/main.cpp.o -MF CMakeFiles/cubeev.dir/main.cpp.o.d -o CMakeFiles/cubeev.dir/main.cpp.o -c /Users/ousuke/cubeev/main.cpp

CMakeFiles/cubeev.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cubeev.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ousuke/cubeev/main.cpp > CMakeFiles/cubeev.dir/main.cpp.i

CMakeFiles/cubeev.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cubeev.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ousuke/cubeev/main.cpp -o CMakeFiles/cubeev.dir/main.cpp.s

CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o: CMakeFiles/cubeev.dir/flags.make
CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o: ../evaluator/cevaluator.cpp
CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o: CMakeFiles/cubeev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ousuke/cubeev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o -MF CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o.d -o CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o -c /Users/ousuke/cubeev/evaluator/cevaluator.cpp

CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ousuke/cubeev/evaluator/cevaluator.cpp > CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.i

CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ousuke/cubeev/evaluator/cevaluator.cpp -o CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.s

CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o: CMakeFiles/cubeev.dir/flags.make
CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o: ../evaluator/csquares.cpp
CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o: CMakeFiles/cubeev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ousuke/cubeev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o -MF CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o.d -o CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o -c /Users/ousuke/cubeev/evaluator/csquares.cpp

CMakeFiles/cubeev.dir/evaluator/csquares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cubeev.dir/evaluator/csquares.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ousuke/cubeev/evaluator/csquares.cpp > CMakeFiles/cubeev.dir/evaluator/csquares.cpp.i

CMakeFiles/cubeev.dir/evaluator/csquares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cubeev.dir/evaluator/csquares.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ousuke/cubeev/evaluator/csquares.cpp -o CMakeFiles/cubeev.dir/evaluator/csquares.cpp.s

# Object files for target cubeev
cubeev_OBJECTS = \
"CMakeFiles/cubeev.dir/main.cpp.o" \
"CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o" \
"CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o"

# External object files for target cubeev
cubeev_EXTERNAL_OBJECTS =

cubeev: CMakeFiles/cubeev.dir/main.cpp.o
cubeev: CMakeFiles/cubeev.dir/evaluator/cevaluator.cpp.o
cubeev: CMakeFiles/cubeev.dir/evaluator/csquares.cpp.o
cubeev: CMakeFiles/cubeev.dir/build.make
cubeev: CMakeFiles/cubeev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ousuke/cubeev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cubeev"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cubeev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cubeev.dir/build: cubeev
.PHONY : CMakeFiles/cubeev.dir/build

CMakeFiles/cubeev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cubeev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cubeev.dir/clean

CMakeFiles/cubeev.dir/depend:
	cd /Users/ousuke/cubeev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ousuke/cubeev /Users/ousuke/cubeev /Users/ousuke/cubeev/build /Users/ousuke/cubeev/build /Users/ousuke/cubeev/build/CMakeFiles/cubeev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cubeev.dir/depend

