cmake_minimum_required(VERSION 3.21)
project(C4_s21_math_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C4_s21_math_1
        src/math.c
        src/s21_math.c
        src/s21_math.h)
