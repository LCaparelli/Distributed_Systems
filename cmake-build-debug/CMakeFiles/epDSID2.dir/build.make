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
CMAKE_COMMAND = /home/darocha/Downloads/CLion-2019.1.2/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/darocha/Downloads/CLion-2019.1.2/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darocha/CLionProjects/epDSID2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darocha/CLionProjects/epDSID2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/epDSID2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/epDSID2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/epDSID2.dir/flags.make

CMakeFiles/epDSID2.dir/main.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/epDSID2.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/main.cpp.o -c /home/darocha/CLionProjects/epDSID2/main.cpp

CMakeFiles/epDSID2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/main.cpp > CMakeFiles/epDSID2.dir/main.cpp.i

CMakeFiles/epDSID2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/main.cpp -o CMakeFiles/epDSID2.dir/main.cpp.s

CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o: ../ServerEndpoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o -c /home/darocha/CLionProjects/epDSID2/ServerEndpoint.cpp

CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/ServerEndpoint.cpp > CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.i

CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/ServerEndpoint.cpp -o CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.s

CMakeFiles/epDSID2.dir/socket/Socket.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/socket/Socket.cpp.o: ../socket/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/epDSID2.dir/socket/Socket.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/socket/Socket.cpp.o -c /home/darocha/CLionProjects/epDSID2/socket/Socket.cpp

CMakeFiles/epDSID2.dir/socket/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/socket/Socket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/socket/Socket.cpp > CMakeFiles/epDSID2.dir/socket/Socket.cpp.i

CMakeFiles/epDSID2.dir/socket/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/socket/Socket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/socket/Socket.cpp -o CMakeFiles/epDSID2.dir/socket/Socket.cpp.s

CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o: ../socket/ServerSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o -c /home/darocha/CLionProjects/epDSID2/socket/ServerSocket.cpp

CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/socket/ServerSocket.cpp > CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.i

CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/socket/ServerSocket.cpp -o CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.s

CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o: ../model/AccountModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o -c /home/darocha/CLionProjects/epDSID2/model/AccountModel.cpp

CMakeFiles/epDSID2.dir/model/AccountModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/model/AccountModel.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/model/AccountModel.cpp > CMakeFiles/epDSID2.dir/model/AccountModel.cpp.i

CMakeFiles/epDSID2.dir/model/AccountModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/model/AccountModel.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/model/AccountModel.cpp -o CMakeFiles/epDSID2.dir/model/AccountModel.cpp.s

CMakeFiles/epDSID2.dir/service/AccountService.cpp.o: CMakeFiles/epDSID2.dir/flags.make
CMakeFiles/epDSID2.dir/service/AccountService.cpp.o: ../service/AccountService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/epDSID2.dir/service/AccountService.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epDSID2.dir/service/AccountService.cpp.o -c /home/darocha/CLionProjects/epDSID2/service/AccountService.cpp

CMakeFiles/epDSID2.dir/service/AccountService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epDSID2.dir/service/AccountService.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darocha/CLionProjects/epDSID2/service/AccountService.cpp > CMakeFiles/epDSID2.dir/service/AccountService.cpp.i

CMakeFiles/epDSID2.dir/service/AccountService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epDSID2.dir/service/AccountService.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darocha/CLionProjects/epDSID2/service/AccountService.cpp -o CMakeFiles/epDSID2.dir/service/AccountService.cpp.s

# Object files for target epDSID2
epDSID2_OBJECTS = \
"CMakeFiles/epDSID2.dir/main.cpp.o" \
"CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o" \
"CMakeFiles/epDSID2.dir/socket/Socket.cpp.o" \
"CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o" \
"CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o" \
"CMakeFiles/epDSID2.dir/service/AccountService.cpp.o"

# External object files for target epDSID2
epDSID2_EXTERNAL_OBJECTS =

epDSID2: CMakeFiles/epDSID2.dir/main.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/ServerEndpoint.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/socket/Socket.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/socket/ServerSocket.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/model/AccountModel.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/service/AccountService.cpp.o
epDSID2: CMakeFiles/epDSID2.dir/build.make
epDSID2: CMakeFiles/epDSID2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable epDSID2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epDSID2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/epDSID2.dir/build: epDSID2

.PHONY : CMakeFiles/epDSID2.dir/build

CMakeFiles/epDSID2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/epDSID2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/epDSID2.dir/clean

CMakeFiles/epDSID2.dir/depend:
	cd /home/darocha/CLionProjects/epDSID2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darocha/CLionProjects/epDSID2 /home/darocha/CLionProjects/epDSID2 /home/darocha/CLionProjects/epDSID2/cmake-build-debug /home/darocha/CLionProjects/epDSID2/cmake-build-debug /home/darocha/CLionProjects/epDSID2/cmake-build-debug/CMakeFiles/epDSID2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/epDSID2.dir/depend

