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
CMAKE_SOURCE_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer"

# Include any dependencies generated for this target.
include CMakeFiles/dimmer-client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dimmer-client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dimmer-client.dir/flags.make

CMakeFiles/dimmer-client.dir/src/main.c.o: CMakeFiles/dimmer-client.dir/flags.make
CMakeFiles/dimmer-client.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dimmer-client.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dimmer-client.dir/src/main.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/main.c"

CMakeFiles/dimmer-client.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dimmer-client.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/main.c" > CMakeFiles/dimmer-client.dir/src/main.c.i

CMakeFiles/dimmer-client.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dimmer-client.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/main.c" -o CMakeFiles/dimmer-client.dir/src/main.c.s

CMakeFiles/dimmer-client.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/dimmer-client.dir/src/main.c.o.requires

CMakeFiles/dimmer-client.dir/src/main.c.o.provides: CMakeFiles/dimmer-client.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/dimmer-client.dir/build.make CMakeFiles/dimmer-client.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/dimmer-client.dir/src/main.c.o.provides

CMakeFiles/dimmer-client.dir/src/main.c.o.provides.build: CMakeFiles/dimmer-client.dir/src/main.c.o


CMakeFiles/dimmer-client.dir/src/dimmer.c.o: CMakeFiles/dimmer-client.dir/flags.make
CMakeFiles/dimmer-client.dir/src/dimmer.c.o: src/dimmer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dimmer-client.dir/src/dimmer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dimmer-client.dir/src/dimmer.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/dimmer.c"

CMakeFiles/dimmer-client.dir/src/dimmer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dimmer-client.dir/src/dimmer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/dimmer.c" > CMakeFiles/dimmer-client.dir/src/dimmer.c.i

CMakeFiles/dimmer-client.dir/src/dimmer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dimmer-client.dir/src/dimmer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/src/dimmer.c" -o CMakeFiles/dimmer-client.dir/src/dimmer.c.s

CMakeFiles/dimmer-client.dir/src/dimmer.c.o.requires:

.PHONY : CMakeFiles/dimmer-client.dir/src/dimmer.c.o.requires

CMakeFiles/dimmer-client.dir/src/dimmer.c.o.provides: CMakeFiles/dimmer-client.dir/src/dimmer.c.o.requires
	$(MAKE) -f CMakeFiles/dimmer-client.dir/build.make CMakeFiles/dimmer-client.dir/src/dimmer.c.o.provides.build
.PHONY : CMakeFiles/dimmer-client.dir/src/dimmer.c.o.provides

CMakeFiles/dimmer-client.dir/src/dimmer.c.o.provides.build: CMakeFiles/dimmer-client.dir/src/dimmer.c.o


# Object files for target dimmer-client
dimmer__client_OBJECTS = \
"CMakeFiles/dimmer-client.dir/src/main.c.o" \
"CMakeFiles/dimmer-client.dir/src/dimmer.c.o"

# External object files for target dimmer-client
dimmer__client_EXTERNAL_OBJECTS =

dimmer-client: CMakeFiles/dimmer-client.dir/src/main.c.o
dimmer-client: CMakeFiles/dimmer-client.dir/src/dimmer.c.o
dimmer-client: CMakeFiles/dimmer-client.dir/build.make
dimmer-client: /usr/local/lib/libanjay.a
dimmer-client: /usr/local/lib/libavs_coap.a
dimmer-client: /usr/local/lib/libavs_algorithm.a
dimmer-client: /usr/local/lib/libavs_net_mbedtls.a
dimmer-client: /usr/local/lib/libavs_crypto_mbedtls.a
dimmer-client: /usr/local/lib/libavs_persistence.a
dimmer-client: /usr/local/lib/libavs_rbtree.a
dimmer-client: /usr/lib/x86_64-linux-gnu/libmbedtls.so
dimmer-client: /usr/lib/x86_64-linux-gnu/libmbedx509.so
dimmer-client: /usr/lib/x86_64-linux-gnu/libmbedcrypto.so
dimmer-client: /usr/local/lib/libavs_sched.a
dimmer-client: /usr/local/lib/libavs_stream_net.a
dimmer-client: /usr/local/lib/libavs_stream.a
dimmer-client: /usr/local/lib/libavs_buffer.a
dimmer-client: /usr/local/lib/libavs_url.a
dimmer-client: /usr/local/lib/libavs_list.a
dimmer-client: /usr/local/lib/libavs_utils.a
dimmer-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
dimmer-client: /usr/local/lib/libavs_log.a
dimmer-client: /usr/local/lib/libavs_list.a
dimmer-client: /usr/local/lib/libavs_utils.a
dimmer-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
dimmer-client: /usr/local/lib/libavs_log.a
dimmer-client: CMakeFiles/dimmer-client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable dimmer-client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dimmer-client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dimmer-client.dir/build: dimmer-client

.PHONY : CMakeFiles/dimmer-client.dir/build

CMakeFiles/dimmer-client.dir/requires: CMakeFiles/dimmer-client.dir/src/main.c.o.requires
CMakeFiles/dimmer-client.dir/requires: CMakeFiles/dimmer-client.dir/src/dimmer.c.o.requires

.PHONY : CMakeFiles/dimmer-client.dir/requires

CMakeFiles/dimmer-client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dimmer-client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dimmer-client.dir/clean

CMakeFiles/dimmer-client.dir/depend:
	cd "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/Dimmer/CMakeFiles/dimmer-client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dimmer-client.dir/depend

