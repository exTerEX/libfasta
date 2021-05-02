add_library(${PROJECT_NAME} STATIC block.cpp fasta.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include>)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES LINKER_LANGUAGE CXX
             SOVERSION ${PROJECT_VERSION_MAJOR}
             PREFIX lib
             CXX_STANDARD 11)
