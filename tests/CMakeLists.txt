include(CTest)

set(CMAKE_EXECUTABLE_SUFFIX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Added tests
create_test(test_block)

enable_testing()
