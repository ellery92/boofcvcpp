cmake_minimum_required(VERSION 3.10)
project(boofcv)

set(CMAKE_BUILD_TYPE Debug)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-DDEBUG)
  add_definitions(-D_DEBUG)
endif()

if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(src)

file(GLOB boofcv-SRCS
  test/main.cpp
  src/geo/struct/point/*.cpp
  src/geo/struct/line/*.cpp
  src/geo/struct/shapes/*.cpp
  # src/geo/geometry/*.cpp
  )

add_executable(boofcv ${boofcv-SRCS})
target_compile_options( boofcv PUBLIC -std=c++11 -fpermissive -w -Wall )
