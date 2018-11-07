cmake_minimum_required(VERSION 3.12)

file(
        GLOB srcs
        DLFileKit.cpp
)

add_library(DLFileKit ${srcs})

if (${CMAKE_BUILD_TYPE} MATCHES "Release")
    install(FILES DLFileKit.h DESTINATION include)
    install(
            TARGETS DLFileKit
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib
    )
endif ()