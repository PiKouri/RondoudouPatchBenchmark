# CMakeList.txt : CMake project for StringBenchmarks, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

# Include Google Benchmark
include(../cmake/GoogleBenchmark.cmake)

# Add source to this project's executable.
add_executable (CipherBenchmarks "rondoudou_patch2.cpp" "rondoudou_patch2.h")

# Link Google Benchmark to the project
target_link_libraries(CipherBenchmarks benchmark::benchmark)

# Link Shlwapi to the project
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    target_link_libraries(CipherBenchmarks Shlwapi)
endif()

# TODO: Add tests and install targets if needed.
