cmake_minimum_required(VERSION 3.14)
project(list_assignment C)

set(CMAKE_C_STANDARD 11)

add_executable(list_assignment main.c list.c list.h)