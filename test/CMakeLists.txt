include(CTest)

# test_block
add_executable(block test_block.cpp)
target_link_libraries(block ${PROJECT_NAME})
add_test(test_block block)
set_tests_properties(
  test_block PROPERTIES FAIL_REGULAR_EXPRESSION "(Exception|Assertion|failed.)"
                        TIMEOUT 120)
