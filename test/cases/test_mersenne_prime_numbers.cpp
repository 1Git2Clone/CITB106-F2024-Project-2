#include "./test_mersenne_prime_numbers.h"
#include "../../src/utils/math.cpp"
#include <gtest/gtest.h>

TEST(MersennePrimeNumbersTest, Assertions) {
  std::vector<unsigned long long> first_nine_mersenne_primes =
      get_first_n_amount_of_mersenne_prime_nums<unsigned long long>(9ull);

  std::vector<unsigned long long> expected_first_nine_mersenne_primes = {
      3,
      7,
      31,
      127,
      8'191,
      131'071,
      524'287,
      2'147'483'647,
      2'305'843'009'213'693'951};

  ASSERT_EQ(first_nine_mersenne_primes, expected_first_nine_mersenne_primes);

  ASSERT_FALSE(is_mersenne_prime(15));
  ASSERT_FALSE(is_mersenne_prime(63));

  ASSERT_TRUE(is_mersenne(8'191));
  ASSERT_TRUE(is_mersenne_prime(8'191));

  return;
}
