enable_testing()

file(GLOB TEST_SRCS
  "cases/*.cpp"
  "cases/*.h"
)

# include
include_directories(
  ${PROJECT_SOURCE_DIR}/src
)

# Targets
add_executable(
  all_tests
  main.cpp
  ${TEST_SRCS}
)

target_link_libraries(
  all_tests
  PRIVATE
  GTest::gtest_main
)

include(GoogleTest)
add_test(NAME all_tests COMMAND ${CMAKE_BINARY_DIR}/test/all_tests)
gtest_discover_tests(all_tests)
