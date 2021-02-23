cmake_minimum_required(VERSION 3.1)
project(mult-client C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(anjay REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
               src/main.c
               src/dimmer.h
               src/dimmer.c
               src/light_control.h
               src/light_control.c
               src/presence_captor.h
               src/presence_captor.c
               src/on_off_switch.h
               src/on_off_switch.c)

target_link_libraries(${PROJECT_NAME} PRIVATE anjay)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
