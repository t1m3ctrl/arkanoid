# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\prog-practice\course work 1 course\arkanoid"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\prog-practice\course work 1 course\arkanoid\build"

# Include any dependencies generated for this target.
include CMakeFiles/CMakeSFMLProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CMakeSFMLProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CMakeSFMLProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CMakeSFMLProject.dir/flags.make

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/flags.make
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/includes_CXX.rsp
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: D:/prog-practice/course\ work\ 1\ course/arkanoid/src/main.cpp
CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj: CMakeFiles/CMakeSFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\prog-practice\course work 1 course\arkanoid\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj -MF CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.obj.d -o CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.obj -c "D:\prog-practice\course work 1 course\arkanoid\src\main.cpp"

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\prog-practice\course work 1 course\arkanoid\src\main.cpp" > CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.i

CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\prog-practice\course work 1 course\arkanoid\src\main.cpp" -o CMakeFiles\CMakeSFMLProject.dir\src\main.cpp.s

# Object files for target CMakeSFMLProject
CMakeSFMLProject_OBJECTS = \
"CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj"

# External object files for target CMakeSFMLProject
CMakeSFMLProject_EXTERNAL_OBJECTS =

CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/src/main.cpp.obj
CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/build.make
CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-graphics-d.a
CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-window-d.a
CMakeSFMLProject.exe: _deps/sfml-build/lib/libsfml-system-d.a
CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/linkLibs.rsp
CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/objects1.rsp
CMakeSFMLProject.exe: CMakeFiles/CMakeSFMLProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\prog-practice\course work 1 course\arkanoid\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CMakeSFMLProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CMakeSFMLProject.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -E copy "D:/prog-practice/course work 1 course/arkanoid/build/_deps/sfml-build/lib/sfml-graphics-d-2.dll" "D:/prog-practice/course work 1 course/arkanoid/build/_deps/sfml-build/lib/sfml-window-d-2.dll" "D:/prog-practice/course work 1 course/arkanoid/build/_deps/sfml-build/lib/sfml-system-d-2.dll" "D:/prog-practice/course work 1 course/arkanoid/build"

# Rule to build all files generated by this target.
CMakeFiles/CMakeSFMLProject.dir/build: CMakeSFMLProject.exe
.PHONY : CMakeFiles/CMakeSFMLProject.dir/build

CMakeFiles/CMakeSFMLProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CMakeSFMLProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CMakeSFMLProject.dir/clean

CMakeFiles/CMakeSFMLProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\prog-practice\course work 1 course\arkanoid" "D:\prog-practice\course work 1 course\arkanoid" "D:\prog-practice\course work 1 course\arkanoid\build" "D:\prog-practice\course work 1 course\arkanoid\build" "D:\prog-practice\course work 1 course\arkanoid\build\CMakeFiles\CMakeSFMLProject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CMakeSFMLProject.dir/depend
