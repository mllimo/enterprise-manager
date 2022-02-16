cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -std=c++17 -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++17")

project(prueba-tecnica)

add_subdirectory(src)