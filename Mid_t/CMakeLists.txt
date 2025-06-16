cmake_minimum_required(VERSION 3.31)
project(mocC C)

set(CMAKE_C_STANDARD 11)

add_executable(mocC main.c)

target_link_libraries(mocC m)
