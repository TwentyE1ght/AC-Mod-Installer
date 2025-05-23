cmake_minimum_required(VERSION 3.30)
project(bit7z)

add_library(bit7z INTERFACE)

target_include_directories(bit7z
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
