cmake_minimum_required(VERSION 3.10)
project(
  GuessNumber
  LANGUAGES C
  VERSION 0.1
  DESCRIPTION "Play guess the number on CLI"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG "-g3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

add_executable(${CMAKE_PROJECT_NAME})
target_include_directories(${CMAKE_PROJECT_NAME}
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
)

add_subdirectory("${CMAKE_SOURCE_DIR}/src")
