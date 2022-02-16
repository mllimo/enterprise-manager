cmake_minimum_required(VERSION 3.20)

project(manager)

add_executable(manager)

target_sources(manager
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/manager.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/action.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/get_action.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/get_manual.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/get_file.h

  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/action.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/get_action.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/get_manual.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/get_file.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/enterprise-manager.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/manager.cc

)

target_include_directories(manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(manager enterprise)