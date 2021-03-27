cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(
  fasta
  LANGUAGES CXX
  VERSION 0.1.0)

set(CXX_STANDARD 14)

set(CMAKE_STATIC_LIBRARY_SUFFIX .so)

include_directories(include)

add_library(${PROJECT_NAME} STATIC src/fasta.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include>)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES LINKER_LANGUAGE CXX PREFIX lib)

add_executable(main example/main.cpp)
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(main ${PROJECT_NAME})
