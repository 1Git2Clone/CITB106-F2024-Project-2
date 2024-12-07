#include "./test_difference.h"
#include "../../src/utils/set_math.cpp"
#include <gtest/gtest.h>

TEST(DifferenceTest, AssertionsSetSet) {
  std::set<int> a = {1, 2, 3};
  std::set<int> b = {2, 3, 4, 5};
  std::set<int> expected_diff = {1};
  std::set<int> received_diff = set_difference(a, b);
  ASSERT_EQ(expected_diff, received_diff);

  return;
}

TEST(DifferenceTest, AssertionsVecSet) {
  std::set<int> a = {1, 2, 3};
  std::set<int> b = {2, 3, 4, 5};
  std::vector<int> expected_diff = {1};
  std::vector<int> received_diff = vec_difference(a, b);

  ASSERT_EQ(expected_diff, received_diff);

  return;
}

TEST(DifferenceTest, AssertionsVecVec) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {2, 3, 4, 5};
  std::vector<int> expected_diff = {1};
  std::vector<int> received_diff = vec_difference(a, b);

  ASSERT_EQ(expected_diff, received_diff);

  return;
}
