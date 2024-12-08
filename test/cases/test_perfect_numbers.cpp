#include "./test_perfect_numbers.hpp"
#include "../../src/utils/perfect_nums.hpp"

#include <climits>
#include <gtest/gtest.h>

TEST(PerfectNumbersTest, Assertions) {
  std::vector<int> perfect_nums = get_perfect_nums_in_interval(6, 8129);
  std::vector<int> expected_perfect_nums = {6, 28, 496, 8128};

  ASSERT_EQ(perfect_nums, expected_perfect_nums);

  // Check if all numbers are perfect
  for (const int &num : perfect_nums) {
    EXPECT_TRUE(is_perfect(num));
  }

  return;
}

TEST(PerfectNumbersTest, EdgeCases) {
  std::vector<long long> perfect_nums =
      get_perfect_nums_in_interval(LLONG_MAX, LLONG_MIN);
  std::vector<long long> expected_perfect_nums = {};

  ASSERT_EQ(perfect_nums, expected_perfect_nums);

  return;
}

TEST(PerfectNumbersTest, AssertionsWithRanges) {
  std::ranges::iota_view<int, int> range = std::ranges::views::iota(6, 8129);
  std::vector<int> perfect_nums = get_perfect_nums_in_range(range);
  std::vector<int> expected_perfect_nums = {6, 28, 496, 8128};

  ASSERT_EQ(perfect_nums, expected_perfect_nums);

  // Check if all numbers are perfect
  for (const int &num : perfect_nums) {
    EXPECT_TRUE(is_perfect(num));
  }

  return;
}

// On MSVC invalid ranges like these are hard errrors.
// ```
//  C:\Program Files\Microsoft Visual
//  Studio\2022\Enterprise\VC\Tools\MSVC\14.42.34433\include\ranges(982) :
//  Assertion failed: Per N4981 [range.iota.view]/8, the first argument must
//  not exceed the second when their types are totally ordered.
// ```
#ifndef _WIN32
TEST(PerfectNumbersTest, EdgeCasesWithRanges) {
  std::ranges::iota_view<long long, long long> range =
      std::ranges::views::iota(LLONG_MAX, 0ll);
  std::vector<long long> perfect_nums = get_perfect_nums_in_range(range);
  std::vector<long long> expected_perfect_nums = {};

  ASSERT_EQ(perfect_nums, expected_perfect_nums);

  return;
}
#endif
