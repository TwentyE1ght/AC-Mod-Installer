cmake_minimum_required(VERSION 3.16)
project(AC_Mod_Installer)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/main.cpp
        src/checks.cpp
        src/menu.cpp
)

add_subdirectory(extlibs/bit7z)

add_executable(AC_Mod_Installer ${SOURCES})

target_link_libraries(AC_Mod_Installer PRIVATE bit7z)

target_include_directories(AC_Mod_Installer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")