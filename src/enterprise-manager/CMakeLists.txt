cmake_minimum_required(VERSION 3.20)

project(enterprise-manager)

add_executable(enterprise-manager)

target_sources(enterprise-manager 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/enterprise-manager.cc
)

target_include_directories(enterprise-manager PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(enterprise-manager enterprise)