cmake_minimum_required(VERSION 3.20)

add_executable(test-enterprise)

target_sources(test-enterprise
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-main.cc 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-test.cc
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

target_link_libraries(test-enterprise  gtest_main gmock_main gmock gtest pthread)

target_include_directories(test-enterprise 
  PRIVATE ${CONAN_INCLUDE_DIRS_GTEST}
)