cmake_minimum_required(VERSION 3.12)

file(
        GLOB tests
        test.cpp
)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

link_libraries(
        DLFileKit
)

add_executable(test ${tests})