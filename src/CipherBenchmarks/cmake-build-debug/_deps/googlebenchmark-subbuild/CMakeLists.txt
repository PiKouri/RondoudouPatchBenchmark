# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.19.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(googlebenchmark-populate NONE)

include(ExternalProject)
ExternalProject_Add(googlebenchmark-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/google/benchmark.git" "GIT_TAG" "origin/master"
                    SOURCE_DIR          "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src"
                    BINARY_DIR          "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


