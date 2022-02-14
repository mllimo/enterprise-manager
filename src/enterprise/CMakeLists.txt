cmake_minimum_required(VERSION 3.20)

add_library(enterprise STATIC)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

target_sources(enterprise 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/test.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cc
)

target_include_directories(enterprise PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(enterprise ${CONAN_LIBS})
