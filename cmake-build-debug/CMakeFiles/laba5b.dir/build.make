# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\CLionProjects\laba5b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\CLionProjects\laba5b\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba5b.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/laba5b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba5b.dir/flags.make

CMakeFiles/laba5b.dir/main.c.obj: CMakeFiles/laba5b.dir/flags.make
CMakeFiles/laba5b.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\CLionProjects\laba5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/laba5b.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\laba5b.dir\main.c.obj -c C:\Users\user\CLionProjects\laba5b\main.c

CMakeFiles/laba5b.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/laba5b.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\user\CLionProjects\laba5b\main.c > CMakeFiles\laba5b.dir\main.c.i

CMakeFiles/laba5b.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/laba5b.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\user\CLionProjects\laba5b\main.c -o CMakeFiles\laba5b.dir\main.c.s

# Object files for target laba5b
laba5b_OBJECTS = \
"CMakeFiles/laba5b.dir/main.c.obj"

# External object files for target laba5b
laba5b_EXTERNAL_OBJECTS =

laba5b.exe: CMakeFiles/laba5b.dir/main.c.obj
laba5b.exe: CMakeFiles/laba5b.dir/build.make
laba5b.exe: libs/data_structures/libdata_structures.a
laba5b.exe: CMakeFiles/laba5b.dir/linklibs.rsp
laba5b.exe: CMakeFiles/laba5b.dir/objects1.rsp
laba5b.exe: CMakeFiles/laba5b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\CLionProjects\laba5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable laba5b.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\laba5b.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba5b.dir/build: laba5b.exe
.PHONY : CMakeFiles/laba5b.dir/build

CMakeFiles/laba5b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\laba5b.dir\cmake_clean.cmake
.PHONY : CMakeFiles/laba5b.dir/clean

CMakeFiles/laba5b.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\CLionProjects\laba5b C:\Users\user\CLionProjects\laba5b C:\Users\user\CLionProjects\laba5b\cmake-build-debug C:\Users\user\CLionProjects\laba5b\cmake-build-debug C:\Users\user\CLionProjects\laba5b\cmake-build-debug\CMakeFiles\laba5b.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba5b.dir/depend

