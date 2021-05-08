
if(NOT "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitinfo.txt" IS_NEWER_THAN "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  clone --no-checkout "https://github.com/google/benchmark.git" "googlebenchmark-src"
    WORKING_DIRECTORY "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/benchmark.git'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"  checkout origin/master --
  WORKING_DIRECTORY "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'origin/master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitinfo.txt"
    "D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'D:/J-R/Travail/INSA/4A/PIR/TestBenchmark/GoogleBenchmark-CMake-Example-master/src/CipherBenchmarks/cmake-build-debug/_deps/googlebenchmark-subbuild/googlebenchmark-populate-prefix/src/googlebenchmark-populate-stamp/googlebenchmark-populate-gitclone-lastrun.txt'")
endif()

