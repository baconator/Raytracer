cmake_minimum_required(VERSION 3.1)
project(Assignment3)

set(CMAKE_CXX_COMPILER "clang++-3.4")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -stdlib=libc++")

add_subdirectory(src)