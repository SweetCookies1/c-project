cmake_minimum_required(VERSION 3.20)
project(laba5b C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5b main.c)

add_subdirectory(libs)
target_link_libraries(laba5b data_structures)
target_link_libraries(laba5b Algorithms)