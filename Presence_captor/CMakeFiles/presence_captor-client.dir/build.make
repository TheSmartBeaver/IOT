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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor"

# Include any dependencies generated for this target.
include CMakeFiles/presence_captor-client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/presence_captor-client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/presence_captor-client.dir/flags.make

CMakeFiles/presence_captor-client.dir/src/main.c.o: CMakeFiles/presence_captor-client.dir/flags.make
CMakeFiles/presence_captor-client.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/presence_captor-client.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/presence_captor-client.dir/src/main.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/main.c"

CMakeFiles/presence_captor-client.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/presence_captor-client.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/main.c" > CMakeFiles/presence_captor-client.dir/src/main.c.i

CMakeFiles/presence_captor-client.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/presence_captor-client.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/main.c" -o CMakeFiles/presence_captor-client.dir/src/main.c.s

CMakeFiles/presence_captor-client.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/presence_captor-client.dir/src/main.c.o.requires

CMakeFiles/presence_captor-client.dir/src/main.c.o.provides: CMakeFiles/presence_captor-client.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/presence_captor-client.dir/build.make CMakeFiles/presence_captor-client.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/presence_captor-client.dir/src/main.c.o.provides

CMakeFiles/presence_captor-client.dir/src/main.c.o.provides.build: CMakeFiles/presence_captor-client.dir/src/main.c.o


CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o: CMakeFiles/presence_captor-client.dir/flags.make
CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o: src/presence_captor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/presence_captor.c"

CMakeFiles/presence_captor-client.dir/src/presence_captor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/presence_captor-client.dir/src/presence_captor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/presence_captor.c" > CMakeFiles/presence_captor-client.dir/src/presence_captor.c.i

CMakeFiles/presence_captor-client.dir/src/presence_captor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/presence_captor-client.dir/src/presence_captor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/src/presence_captor.c" -o CMakeFiles/presence_captor-client.dir/src/presence_captor.c.s

CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.requires:

.PHONY : CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.requires

CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.provides: CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.requires
	$(MAKE) -f CMakeFiles/presence_captor-client.dir/build.make CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.provides.build
.PHONY : CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.provides

CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.provides.build: CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o


# Object files for target presence_captor-client
presence_captor__client_OBJECTS = \
"CMakeFiles/presence_captor-client.dir/src/main.c.o" \
"CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o"

# External object files for target presence_captor-client
presence_captor__client_EXTERNAL_OBJECTS =

presence_captor-client: CMakeFiles/presence_captor-client.dir/src/main.c.o
presence_captor-client: CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o
presence_captor-client: CMakeFiles/presence_captor-client.dir/build.make
presence_captor-client: /usr/local/lib/libanjay.a
presence_captor-client: /usr/local/lib/libavs_coap.a
presence_captor-client: /usr/local/lib/libavs_algorithm.a
presence_captor-client: /usr/local/lib/libavs_net_mbedtls.a
presence_captor-client: /usr/local/lib/libavs_crypto_mbedtls.a
presence_captor-client: /usr/local/lib/libavs_persistence.a
presence_captor-client: /usr/local/lib/libavs_rbtree.a
presence_captor-client: /usr/lib/x86_64-linux-gnu/libmbedtls.so
presence_captor-client: /usr/lib/x86_64-linux-gnu/libmbedx509.so
presence_captor-client: /usr/lib/x86_64-linux-gnu/libmbedcrypto.so
presence_captor-client: /usr/local/lib/libavs_sched.a
presence_captor-client: /usr/local/lib/libavs_stream_net.a
presence_captor-client: /usr/local/lib/libavs_stream.a
presence_captor-client: /usr/local/lib/libavs_buffer.a
presence_captor-client: /usr/local/lib/libavs_url.a
presence_captor-client: /usr/local/lib/libavs_list.a
presence_captor-client: /usr/local/lib/libavs_utils.a
presence_captor-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
presence_captor-client: /usr/local/lib/libavs_log.a
presence_captor-client: /usr/local/lib/libavs_list.a
presence_captor-client: /usr/local/lib/libavs_utils.a
presence_captor-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
presence_captor-client: /usr/local/lib/libavs_log.a
presence_captor-client: CMakeFiles/presence_captor-client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable presence_captor-client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/presence_captor-client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/presence_captor-client.dir/build: presence_captor-client

.PHONY : CMakeFiles/presence_captor-client.dir/build

CMakeFiles/presence_captor-client.dir/requires: CMakeFiles/presence_captor-client.dir/src/main.c.o.requires
CMakeFiles/presence_captor-client.dir/requires: CMakeFiles/presence_captor-client.dir/src/presence_captor.c.o.requires

.PHONY : CMakeFiles/presence_captor-client.dir/requires

CMakeFiles/presence_captor-client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/presence_captor-client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/presence_captor-client.dir/clean

CMakeFiles/presence_captor-client.dir/depend:
	cd "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Presence_captor/CMakeFiles/presence_captor-client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/presence_captor-client.dir/depend

