#include "./test_perfect_numbers.h"

#include "../../src/utils/math.cpp"

#include <gtest/gtest.h>

TEST(PerfectNumbersTest, Assertions) {
  std::vector<int> perfect_nums = get_perfect_nums_from_interval(6, 8128);
  std::vector<int> expected_perfect_nums = {6, 28, 496, 8128};

  ASSERT_EQ(perfect_nums, expected_perfect_nums);

  // Check if all numbers are perfect
  for (const int &num : perfect_nums) {
    EXPECT_TRUE(is_perfect(num));
  }

  return;
}
