cmake_minimum_required(VERSION 3.30)
project(lib01 C)

set(CMAKE_C_STANDARD 23)

add_library(lib01 STATIC library.c)
