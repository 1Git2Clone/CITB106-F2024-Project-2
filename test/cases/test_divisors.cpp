#include "../../src/utils/divisors.hpp"
#include "../../src/utils/primes.hpp"
#include <climits>
#include <gtest/gtest.h>

TEST(DivisorsTest, Assertions) {
  const int of = 180;
  std::vector<int> expected_divisors = {2,  3,  4,  5,  6,  9,  10, 12,
                                        15, 18, 20, 30, 36, 45, 60, 90};
  std::vector<int> received_divisors = get_divisors(of);
  ASSERT_EQ(expected_divisors, received_divisors);

  return;
}

TEST(DifferenceTest, OneEdgeCases) {
  for (int i = 2; i < 500; i++) {
    if (is_prime(i)) {
      ASSERT_EQ(std::vector<int>{i}, get_divisors(i * i));
    }
  }

  return;
}

TEST(DifferenceTest, ZeroEdgeCase) {
  const short of = SHRT_MIN;
  std::vector<short> expected_divisors = {};
  std::vector<short> received_divisors = get_divisors(of);
  ASSERT_EQ(expected_divisors, received_divisors);

  return;
}
