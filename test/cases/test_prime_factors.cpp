#include "./test_prime_factors.h"

#include "../../src/utils/math.cpp"

#include <gtest/gtest.h>

TEST(PrimeFactorsTest, Assertions) {
  int of = 18200;
  std::vector<int> prime_factors = get_prime_factors(of);
  std::vector<int> expected_factors = {2, 5, 7, 13};
}
