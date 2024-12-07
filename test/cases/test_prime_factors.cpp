#include "./test_prime_factors.h"

#include "../../src/utils/primes.cpp"

#include <gtest/gtest.h>
#include <vector>

TEST(PrimeFactorsTest, Assertions) {
  unsigned long of = 6469693230;
  std::vector<unsigned long> prime_factors = get_prime_factors(of);
  std::vector<unsigned long> expected_factors = {2,  3,  5,  7,  11,
                                                 13, 17, 19, 23, 29};
  ASSERT_EQ(prime_factors, expected_factors);
}

TEST(PrimeFactorsTest, EdgeCases) {
  unsigned long of = 0;
  std::vector<unsigned long> prime_factors = get_prime_factors(of);
  std::vector<unsigned long> expected_factors = {};
  ASSERT_EQ(prime_factors, expected_factors);
}

TEST(PrimeFactorsTest, SeveralLowValueEdgeCase) {
  std::vector<int> prime_factors[7];

  for (int i = 2; i <= 8; i++) {
    prime_factors[i - 2] = get_prime_factors(i);
    // Processes {2, 3, 5, 7} in the loop directly.
    if (is_prime(i)) {
      ASSERT_EQ(prime_factors[i - 2], std::vector<int>{i});
    }
  }

  std::vector<int> of_four = {2};
  ASSERT_EQ(prime_factors[2], of_four);

  std::vector<int> of_six = {2, 3};
  ASSERT_EQ(prime_factors[4], of_six);

  std::vector<int> of_eight = {2};
  ASSERT_EQ(prime_factors[6], of_eight);

  return;
}
