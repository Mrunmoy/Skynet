# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\championsurfer3044\CLionProjects\skynet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/skynet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/skynet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/skynet.dir/flags.make

CMakeFiles/skynet.dir/main.c.obj: CMakeFiles/skynet.dir/flags.make
CMakeFiles/skynet.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/skynet.dir/main.c.obj"
	C:\mingw-w64\x86_64-7.2.0-posix-seh-rt_v5-rev1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\skynet.dir\main.c.obj   -c C:\Users\championsurfer3044\CLionProjects\skynet\main.c

CMakeFiles/skynet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/skynet.dir/main.c.i"
	C:\mingw-w64\x86_64-7.2.0-posix-seh-rt_v5-rev1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\championsurfer3044\CLionProjects\skynet\main.c > CMakeFiles\skynet.dir\main.c.i

CMakeFiles/skynet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/skynet.dir/main.c.s"
	C:\mingw-w64\x86_64-7.2.0-posix-seh-rt_v5-rev1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\championsurfer3044\CLionProjects\skynet\main.c -o CMakeFiles\skynet.dir\main.c.s

CMakeFiles/skynet.dir/main.c.obj.requires:

.PHONY : CMakeFiles/skynet.dir/main.c.obj.requires

CMakeFiles/skynet.dir/main.c.obj.provides: CMakeFiles/skynet.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\skynet.dir\build.make CMakeFiles/skynet.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/skynet.dir/main.c.obj.provides

CMakeFiles/skynet.dir/main.c.obj.provides.build: CMakeFiles/skynet.dir/main.c.obj


# Object files for target skynet
skynet_OBJECTS = \
"CMakeFiles/skynet.dir/main.c.obj"

# External object files for target skynet
skynet_EXTERNAL_OBJECTS =

skynet.exe: CMakeFiles/skynet.dir/main.c.obj
skynet.exe: CMakeFiles/skynet.dir/build.make
skynet.exe: CMakeFiles/skynet.dir/linklibs.rsp
skynet.exe: CMakeFiles/skynet.dir/objects1.rsp
skynet.exe: CMakeFiles/skynet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable skynet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\skynet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/skynet.dir/build: skynet.exe

.PHONY : CMakeFiles/skynet.dir/build

CMakeFiles/skynet.dir/requires: CMakeFiles/skynet.dir/main.c.obj.requires

.PHONY : CMakeFiles/skynet.dir/requires

CMakeFiles/skynet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\skynet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/skynet.dir/clean

CMakeFiles/skynet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\championsurfer3044\CLionProjects\skynet C:\Users\championsurfer3044\CLionProjects\skynet C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug C:\Users\championsurfer3044\CLionProjects\skynet\cmake-build-debug\CMakeFiles\skynet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/skynet.dir/depend
