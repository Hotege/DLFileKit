cmake_minimum_required(VERSION 3.12)

file(
        GLOB srcs
        DLFileKit.cpp
)

add_library(DLFileKit ${srcs})