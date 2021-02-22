cmake_minimum_required(VERSION 3.1)
project(presence_captor-client C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

find_package(anjay REQUIRED)

add_executable(${PROJECT_NAME}
               src/main.c
               src/presence_captor.h
               src/presence_captor.c)
target_link_libraries(${PROJECT_NAME} PRIVATE anjay)
