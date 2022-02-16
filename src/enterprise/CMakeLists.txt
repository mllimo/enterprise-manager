cmake_minimum_required(VERSION 3.20)

add_library(enterprise STATIC)

target_sources(enterprise 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/entity.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/entity_type.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/client.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/regexs.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/supplier.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/bill.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/company.h
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/enterprise/status.h

  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/entity.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/regexs.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/client.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/supplier.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/bill.cc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/company.cc
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

target_include_directories(enterprise 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PUBLIC ${CONAN_INCLUDE_DIRS_NLOHMANN_JSON} # creo que no es la mejor opcion
)

target_link_libraries(enterprise ${CONAN_LIBS})

add_subdirectory(test)