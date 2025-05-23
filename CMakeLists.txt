cmake_minimum_required(VERSION 3.30)
project(AC_Mod_Installer)

set(CMAKE_CXX_STANDARD 20)

add_executable(AC_Mod_Installer src/main.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/extlibs/bit7z) # Path to bit7z's repository
# Here you can enable/disable bit7z's build options, e.g.:
# set(BIT7Z_USE_NATIVE_STRING ON CACHE BOOL "enable using native OS strings" FORCE)
target_link_libraries(AC_Mod_Installer PRIVATE bit7z)