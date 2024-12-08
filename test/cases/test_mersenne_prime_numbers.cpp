#include "./test_mersenne_prime_numbers.hpp"
#include "../../src/utils/mersenne.hpp"
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

  return;
}

TEST(MersennePrimeNumbersTest, BasicIsMersennePrimeTests) {
  ASSERT_FALSE(is_mersenne_prime(15));
  ASSERT_FALSE(is_mersenne_prime(63));

  ASSERT_TRUE(is_mersenne_prime(8'191));

  return;
}

TEST(MersennePrimeNumbersTest, EdgeCases) {
  std::vector<int> zero_mersenne_primes =
      get_first_n_amount_of_mersenne_prime_nums(0);

  std::vector<int> expected_mersenne_primes = {};

  ASSERT_EQ(zero_mersenne_primes, expected_mersenne_primes);

  return;
}
