# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-src")
  file(MAKE_DIRECTORY "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-build"
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix"
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/tmp"
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/src/ghc_filesystem-populate-stamp"
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/src"
  "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/src/ghc_filesystem-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/src/ghc_filesystem-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/kwaku/CLionProjects/AC-Mod-Installer/cmake-build-debug/_deps/ghc_filesystem-subbuild/ghc_filesystem-populate-prefix/src/ghc_filesystem-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
