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
CMAKE_SOURCE_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult"

# Include any dependencies generated for this target.
include CMakeFiles/mult-client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mult-client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mult-client.dir/flags.make

CMakeFiles/mult-client.dir/src/main.c.o: CMakeFiles/mult-client.dir/flags.make
CMakeFiles/mult-client.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mult-client.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mult-client.dir/src/main.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/main.c"

CMakeFiles/mult-client.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mult-client.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/main.c" > CMakeFiles/mult-client.dir/src/main.c.i

CMakeFiles/mult-client.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mult-client.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/main.c" -o CMakeFiles/mult-client.dir/src/main.c.s

CMakeFiles/mult-client.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/mult-client.dir/src/main.c.o.requires

CMakeFiles/mult-client.dir/src/main.c.o.provides: CMakeFiles/mult-client.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/mult-client.dir/build.make CMakeFiles/mult-client.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/mult-client.dir/src/main.c.o.provides

CMakeFiles/mult-client.dir/src/main.c.o.provides.build: CMakeFiles/mult-client.dir/src/main.c.o


CMakeFiles/mult-client.dir/src/dimmer.c.o: CMakeFiles/mult-client.dir/flags.make
CMakeFiles/mult-client.dir/src/dimmer.c.o: src/dimmer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mult-client.dir/src/dimmer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mult-client.dir/src/dimmer.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/dimmer.c"

CMakeFiles/mult-client.dir/src/dimmer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mult-client.dir/src/dimmer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/dimmer.c" > CMakeFiles/mult-client.dir/src/dimmer.c.i

CMakeFiles/mult-client.dir/src/dimmer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mult-client.dir/src/dimmer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/dimmer.c" -o CMakeFiles/mult-client.dir/src/dimmer.c.s

CMakeFiles/mult-client.dir/src/dimmer.c.o.requires:

.PHONY : CMakeFiles/mult-client.dir/src/dimmer.c.o.requires

CMakeFiles/mult-client.dir/src/dimmer.c.o.provides: CMakeFiles/mult-client.dir/src/dimmer.c.o.requires
	$(MAKE) -f CMakeFiles/mult-client.dir/build.make CMakeFiles/mult-client.dir/src/dimmer.c.o.provides.build
.PHONY : CMakeFiles/mult-client.dir/src/dimmer.c.o.provides

CMakeFiles/mult-client.dir/src/dimmer.c.o.provides.build: CMakeFiles/mult-client.dir/src/dimmer.c.o


CMakeFiles/mult-client.dir/src/light_control.c.o: CMakeFiles/mult-client.dir/flags.make
CMakeFiles/mult-client.dir/src/light_control.c.o: src/light_control.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mult-client.dir/src/light_control.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mult-client.dir/src/light_control.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/light_control.c"

CMakeFiles/mult-client.dir/src/light_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mult-client.dir/src/light_control.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/light_control.c" > CMakeFiles/mult-client.dir/src/light_control.c.i

CMakeFiles/mult-client.dir/src/light_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mult-client.dir/src/light_control.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/light_control.c" -o CMakeFiles/mult-client.dir/src/light_control.c.s

CMakeFiles/mult-client.dir/src/light_control.c.o.requires:

.PHONY : CMakeFiles/mult-client.dir/src/light_control.c.o.requires

CMakeFiles/mult-client.dir/src/light_control.c.o.provides: CMakeFiles/mult-client.dir/src/light_control.c.o.requires
	$(MAKE) -f CMakeFiles/mult-client.dir/build.make CMakeFiles/mult-client.dir/src/light_control.c.o.provides.build
.PHONY : CMakeFiles/mult-client.dir/src/light_control.c.o.provides

CMakeFiles/mult-client.dir/src/light_control.c.o.provides.build: CMakeFiles/mult-client.dir/src/light_control.c.o


CMakeFiles/mult-client.dir/src/presence_captor.c.o: CMakeFiles/mult-client.dir/flags.make
CMakeFiles/mult-client.dir/src/presence_captor.c.o: src/presence_captor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mult-client.dir/src/presence_captor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mult-client.dir/src/presence_captor.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/presence_captor.c"

CMakeFiles/mult-client.dir/src/presence_captor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mult-client.dir/src/presence_captor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/presence_captor.c" > CMakeFiles/mult-client.dir/src/presence_captor.c.i

CMakeFiles/mult-client.dir/src/presence_captor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mult-client.dir/src/presence_captor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/presence_captor.c" -o CMakeFiles/mult-client.dir/src/presence_captor.c.s

CMakeFiles/mult-client.dir/src/presence_captor.c.o.requires:

.PHONY : CMakeFiles/mult-client.dir/src/presence_captor.c.o.requires

CMakeFiles/mult-client.dir/src/presence_captor.c.o.provides: CMakeFiles/mult-client.dir/src/presence_captor.c.o.requires
	$(MAKE) -f CMakeFiles/mult-client.dir/build.make CMakeFiles/mult-client.dir/src/presence_captor.c.o.provides.build
.PHONY : CMakeFiles/mult-client.dir/src/presence_captor.c.o.provides

CMakeFiles/mult-client.dir/src/presence_captor.c.o.provides.build: CMakeFiles/mult-client.dir/src/presence_captor.c.o


CMakeFiles/mult-client.dir/src/on_off_switch.c.o: CMakeFiles/mult-client.dir/flags.make
CMakeFiles/mult-client.dir/src/on_off_switch.c.o: src/on_off_switch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mult-client.dir/src/on_off_switch.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mult-client.dir/src/on_off_switch.c.o   -c "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/on_off_switch.c"

CMakeFiles/mult-client.dir/src/on_off_switch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mult-client.dir/src/on_off_switch.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/on_off_switch.c" > CMakeFiles/mult-client.dir/src/on_off_switch.c.i

CMakeFiles/mult-client.dir/src/on_off_switch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mult-client.dir/src/on_off_switch.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/src/on_off_switch.c" -o CMakeFiles/mult-client.dir/src/on_off_switch.c.s

CMakeFiles/mult-client.dir/src/on_off_switch.c.o.requires:

.PHONY : CMakeFiles/mult-client.dir/src/on_off_switch.c.o.requires

CMakeFiles/mult-client.dir/src/on_off_switch.c.o.provides: CMakeFiles/mult-client.dir/src/on_off_switch.c.o.requires
	$(MAKE) -f CMakeFiles/mult-client.dir/build.make CMakeFiles/mult-client.dir/src/on_off_switch.c.o.provides.build
.PHONY : CMakeFiles/mult-client.dir/src/on_off_switch.c.o.provides

CMakeFiles/mult-client.dir/src/on_off_switch.c.o.provides.build: CMakeFiles/mult-client.dir/src/on_off_switch.c.o


# Object files for target mult-client
mult__client_OBJECTS = \
"CMakeFiles/mult-client.dir/src/main.c.o" \
"CMakeFiles/mult-client.dir/src/dimmer.c.o" \
"CMakeFiles/mult-client.dir/src/light_control.c.o" \
"CMakeFiles/mult-client.dir/src/presence_captor.c.o" \
"CMakeFiles/mult-client.dir/src/on_off_switch.c.o"

# External object files for target mult-client
mult__client_EXTERNAL_OBJECTS =

mult-client: CMakeFiles/mult-client.dir/src/main.c.o
mult-client: CMakeFiles/mult-client.dir/src/dimmer.c.o
mult-client: CMakeFiles/mult-client.dir/src/light_control.c.o
mult-client: CMakeFiles/mult-client.dir/src/presence_captor.c.o
mult-client: CMakeFiles/mult-client.dir/src/on_off_switch.c.o
mult-client: CMakeFiles/mult-client.dir/build.make
mult-client: /usr/local/lib/libanjay.a
mult-client: /usr/local/lib/libavs_coap.a
mult-client: /usr/local/lib/libavs_algorithm.a
mult-client: /usr/local/lib/libavs_net_mbedtls.a
mult-client: /usr/local/lib/libavs_crypto_mbedtls.a
mult-client: /usr/local/lib/libavs_persistence.a
mult-client: /usr/local/lib/libavs_rbtree.a
mult-client: /usr/lib/x86_64-linux-gnu/libmbedtls.so
mult-client: /usr/lib/x86_64-linux-gnu/libmbedx509.so
mult-client: /usr/lib/x86_64-linux-gnu/libmbedcrypto.so
mult-client: /usr/local/lib/libavs_sched.a
mult-client: /usr/local/lib/libavs_stream_net.a
mult-client: /usr/local/lib/libavs_stream.a
mult-client: /usr/local/lib/libavs_buffer.a
mult-client: /usr/local/lib/libavs_url.a
mult-client: /usr/local/lib/libavs_list.a
mult-client: /usr/local/lib/libavs_utils.a
mult-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
mult-client: /usr/local/lib/libavs_log.a
mult-client: /usr/local/lib/libavs_list.a
mult-client: /usr/local/lib/libavs_utils.a
mult-client: /usr/local/lib/libavs_compat_threading_atomic_spinlock.a
mult-client: /usr/local/lib/libavs_log.a
mult-client: CMakeFiles/mult-client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable mult-client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mult-client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mult-client.dir/build: mult-client

.PHONY : CMakeFiles/mult-client.dir/build

CMakeFiles/mult-client.dir/requires: CMakeFiles/mult-client.dir/src/main.c.o.requires
CMakeFiles/mult-client.dir/requires: CMakeFiles/mult-client.dir/src/dimmer.c.o.requires
CMakeFiles/mult-client.dir/requires: CMakeFiles/mult-client.dir/src/light_control.c.o.requires
CMakeFiles/mult-client.dir/requires: CMakeFiles/mult-client.dir/src/presence_captor.c.o.requires
CMakeFiles/mult-client.dir/requires: CMakeFiles/mult-client.dir/src/on_off_switch.c.o.requires

.PHONY : CMakeFiles/mult-client.dir/requires

CMakeFiles/mult-client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mult-client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mult-client.dir/clean

CMakeFiles/mult-client.dir/depend:
	cd "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult" "/home/totor/Documents/M2/IOT/Anjay/Client's PROJECT/ClientMult/CMakeFiles/mult-client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mult-client.dir/depend

