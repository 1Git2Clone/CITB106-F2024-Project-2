#include "./test_mersenne_numbers.h"
#include "../../src/utils/math.cpp"
#include <gtest/gtest.h>

TEST(MersenneNumbersTest, Assertions) {
  const int begin = 3;
  const int end = 2048;
  const int n = 9;

  std::vector<int> mersenne_a = get_mersenne_nums_in_interval(begin, end);
  std::vector<int> expected_mersenne = {2,   3,   7,   15,   31,  63,
                                        127, 255, 511, 1023, 2047};

  ASSERT_EQ(mersenne_a, expected_mersenne);

  std::vector<int> first_nine_mersenne_numbers =
      get_first_n_amount_of_mersenne_nums(n);
  ASSERT_EQ(mersenne_a, first_nine_mersenne_numbers);

  return;
}
