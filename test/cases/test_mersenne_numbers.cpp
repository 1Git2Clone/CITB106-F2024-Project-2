#include "./test_mersenne_numbers.h"
#include "../../src/utils/math.cpp"
#include <gtest/gtest.h>

TEST(MersenneNumbersTest, Interval) {
  const int begin = 3;
  const int end = 2048;

  std::vector<int> mersenne_in = get_mersenne_nums_in_interval(begin, end);
  std::vector<int> expected_mersenne = {3,   7,   15,  31,   63,
                                        127, 255, 511, 1023, 2047};

  ASSERT_EQ(mersenne_in, expected_mersenne);

  return;
}

TEST(MersenneNumbersTest, NAmount) {
  const int n = 10;

  std::vector<int> expected_mersenne = {3,   7,   15,  31,   63,
                                        127, 255, 511, 1023, 2047};

  ASSERT_EQ(expected_mersenne.size(), n);

  std::vector<int> first_n_mersenne_numbers =
      get_first_n_amount_of_mersenne_nums(n);

  ASSERT_EQ(first_n_mersenne_numbers, expected_mersenne);

  return;
}

TEST(MersenneNumbersTest, BasicIsMersenneTests) {
  std::vector<int> mersenne_nums = {3,   7,   15,   31,   63,   127,
                                    255, 511, 1023, 2047, 4095, 8191};

  for (const int &num : mersenne_nums) {
    ASSERT_TRUE(is_mersenne(num));
    ASSERT_FALSE(is_mersenne(num - 1));
  }

  return;
}

TEST(MersenneNumbersTest, EdgeCases) {
  const int begin = 0;
  const int end = 0;

  std::vector<int> mersenne_in = get_mersenne_nums_in_interval(begin, end);
  std::vector<int> expected_mersenne = {};

  ASSERT_EQ(mersenne_in, expected_mersenne);

  return;
}

TEST(MersenneNumbersTest, HighLowEdgeCase) {
  const long long begin = 999'999'999'999'999'999;
  const long long end = -999'999'999'999'999'999;

  std::vector<long long> mersenne_in =
      get_mersenne_nums_in_interval(begin, end);
  std::vector<long long> expected_mersenne = {};

  ASSERT_EQ(mersenne_in, expected_mersenne);

  return;
}
