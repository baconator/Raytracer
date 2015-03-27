cmake_minimum_required(VERSION 3.1)
project(Assignment3)

set(CMAKE_CXX_COMPILER "clang++-3.5")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -O3 -Rpass-analysis=loop-vectorize -stdlib=libc++")

include_directories(${Assignment3_SOURCE_DIR}/lib/eigen)

add_subdirectory(src)