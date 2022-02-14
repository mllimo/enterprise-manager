cmake_minimum_required(VERSION 3.20)

add_subdirectory(test)

add_library(enterprise STATIC)

target_sources(enterprise 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/test.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cc
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

target_include_directories(enterprise 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PUBLIC ${CONAN_INCLUDE_DIRS_NLOHMANN_JSON} # creo que no es la mejor opcion
)

target_link_libraries(enterprise ${CONAN_LIBS})