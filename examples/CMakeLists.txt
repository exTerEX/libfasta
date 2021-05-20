# Simple read example
add_executable(read read.cpp)
set_target_properties(read PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 11)
target_link_libraries(read ${PROJECT_NAME})

# Read example from compressed format
find_package(Boost 1.70.0 REQUIRED COMPONENTS iostreams)
add_executable(read_gzip read_gzip.cpp)
set_target_properties(read_gzip PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 11)
target_link_libraries(read_gzip ${PROJECT_NAME} Boost::iostreams)
