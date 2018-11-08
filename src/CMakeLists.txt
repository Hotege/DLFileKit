cmake_minimum_required(VERSION 3.12)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(PROJECT_POSTFIX "-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(INSTALL_DIR "${PROJECT_SOURCE_DIR}/lib${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}${PROJECT_POSTFIX}")

file(
        GLOB srcs
        DLFileKit.cpp
)

add_library(DLFileKit ${srcs})

if (${CMAKE_BUILD_TYPE} MATCHES "Release")
    install(FILES DLFileKit.h DESTINATION "${INSTALL_DIR}/include")
    install(
            TARGETS DLFileKit
            ARCHIVE DESTINATION "${INSTALL_DIR}/lib"
            LIBRARY DESTINATION "${INSTALL_DIR}/lib"
    )
endif ()