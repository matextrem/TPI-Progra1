# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mdastugue/Projects/progra-tpi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mdastugue/Projects/progra-tpi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TP_I.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP_I.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP_I.dir/flags.make

CMakeFiles/TP_I.dir/main.c.o: CMakeFiles/TP_I.dir/flags.make
CMakeFiles/TP_I.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mdastugue/Projects/progra-tpi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP_I.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TP_I.dir/main.c.o   -c /Users/mdastugue/Projects/progra-tpi/main.c

CMakeFiles/TP_I.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP_I.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mdastugue/Projects/progra-tpi/main.c > CMakeFiles/TP_I.dir/main.c.i

CMakeFiles/TP_I.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP_I.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mdastugue/Projects/progra-tpi/main.c -o CMakeFiles/TP_I.dir/main.c.s

CMakeFiles/TP_I.dir/main.c.o.requires:

.PHONY : CMakeFiles/TP_I.dir/main.c.o.requires

CMakeFiles/TP_I.dir/main.c.o.provides: CMakeFiles/TP_I.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/TP_I.dir/build.make CMakeFiles/TP_I.dir/main.c.o.provides.build
.PHONY : CMakeFiles/TP_I.dir/main.c.o.provides

CMakeFiles/TP_I.dir/main.c.o.provides.build: CMakeFiles/TP_I.dir/main.c.o


# Object files for target TP_I
TP_I_OBJECTS = \
"CMakeFiles/TP_I.dir/main.c.o"

# External object files for target TP_I
TP_I_EXTERNAL_OBJECTS =

TP_I: CMakeFiles/TP_I.dir/main.c.o
TP_I: CMakeFiles/TP_I.dir/build.make
TP_I: CMakeFiles/TP_I.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mdastugue/Projects/progra-tpi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TP_I"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_I.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP_I.dir/build: TP_I

.PHONY : CMakeFiles/TP_I.dir/build

CMakeFiles/TP_I.dir/requires: CMakeFiles/TP_I.dir/main.c.o.requires

.PHONY : CMakeFiles/TP_I.dir/requires

CMakeFiles/TP_I.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP_I.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP_I.dir/clean

CMakeFiles/TP_I.dir/depend:
	cd /Users/mdastugue/Projects/progra-tpi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mdastugue/Projects/progra-tpi /Users/mdastugue/Projects/progra-tpi /Users/mdastugue/Projects/progra-tpi/cmake-build-debug /Users/mdastugue/Projects/progra-tpi/cmake-build-debug /Users/mdastugue/Projects/progra-tpi/cmake-build-debug/CMakeFiles/TP_I.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP_I.dir/depend
