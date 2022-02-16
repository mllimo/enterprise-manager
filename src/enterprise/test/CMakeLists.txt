cmake_minimum_required(VERSION 3.20)

add_executable(test-enterprise)

target_sources(test-enterprise
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-main.cc 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-entity.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-client.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-client.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-supplier.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-bill.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test-company.cc
)

target_link_libraries(test-enterprise gtest_main gmock_main gmock gtest pthread enterprise)

target_include_directories(test-enterprise 
  PRIVATE ${CONAN_INCLUDE_DIRS_GTEST}
)