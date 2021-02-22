cmake_minimum_required(VERSION 3.1)
project(mult-client C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

find_package(anjay REQUIRED)

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
