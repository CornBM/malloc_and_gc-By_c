# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/corn/system_code/malloc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corn/system_code/malloc/build

# Include any dependencies generated for this target.
include 1.malloc/CMakeFiles/_malloc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 1.malloc/CMakeFiles/_malloc.dir/compiler_depend.make

# Include the progress variables for this target.
include 1.malloc/CMakeFiles/_malloc.dir/progress.make

# Include the compile flags for this target's objects.
include 1.malloc/CMakeFiles/_malloc.dir/flags.make

1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o: 1.malloc/CMakeFiles/_malloc.dir/flags.make
1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o: ../1.malloc/src/malloc.c
1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o: 1.malloc/CMakeFiles/_malloc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/corn/system_code/malloc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o"
	cd /home/corn/system_code/malloc/build/1.malloc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o -MF CMakeFiles/_malloc.dir/src/malloc.c.o.d -o CMakeFiles/_malloc.dir/src/malloc.c.o -c /home/corn/system_code/malloc/1.malloc/src/malloc.c

1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_malloc.dir/src/malloc.c.i"
	cd /home/corn/system_code/malloc/build/1.malloc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/corn/system_code/malloc/1.malloc/src/malloc.c > CMakeFiles/_malloc.dir/src/malloc.c.i

1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_malloc.dir/src/malloc.c.s"
	cd /home/corn/system_code/malloc/build/1.malloc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/corn/system_code/malloc/1.malloc/src/malloc.c -o CMakeFiles/_malloc.dir/src/malloc.c.s

# Object files for target _malloc
_malloc_OBJECTS = \
"CMakeFiles/_malloc.dir/src/malloc.c.o"

# External object files for target _malloc
_malloc_EXTERNAL_OBJECTS =

1.malloc/lib_malloc.a: 1.malloc/CMakeFiles/_malloc.dir/src/malloc.c.o
1.malloc/lib_malloc.a: 1.malloc/CMakeFiles/_malloc.dir/build.make
1.malloc/lib_malloc.a: 1.malloc/CMakeFiles/_malloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/corn/system_code/malloc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library lib_malloc.a"
	cd /home/corn/system_code/malloc/build/1.malloc && $(CMAKE_COMMAND) -P CMakeFiles/_malloc.dir/cmake_clean_target.cmake
	cd /home/corn/system_code/malloc/build/1.malloc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_malloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
1.malloc/CMakeFiles/_malloc.dir/build: 1.malloc/lib_malloc.a
.PHONY : 1.malloc/CMakeFiles/_malloc.dir/build

1.malloc/CMakeFiles/_malloc.dir/clean:
	cd /home/corn/system_code/malloc/build/1.malloc && $(CMAKE_COMMAND) -P CMakeFiles/_malloc.dir/cmake_clean.cmake
.PHONY : 1.malloc/CMakeFiles/_malloc.dir/clean

1.malloc/CMakeFiles/_malloc.dir/depend:
	cd /home/corn/system_code/malloc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corn/system_code/malloc /home/corn/system_code/malloc/1.malloc /home/corn/system_code/malloc/build /home/corn/system_code/malloc/build/1.malloc /home/corn/system_code/malloc/build/1.malloc/CMakeFiles/_malloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 1.malloc/CMakeFiles/_malloc.dir/depend
