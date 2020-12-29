cmake_minimum_required(VERSION 3.10)
project(C-onversion VERSION 0.0.1)

add_library(
    c_onversion
    c_onversion.h
    c_onversion.c
)

add_executable(tests tests.c)

target_link_libraries(tests PRIVATE c_onversion)
