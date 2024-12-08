#ifndef UTILS_PRIMES_HPP
#define UTILS_PRIMES_HPP

#include "concepts.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

/**
 * Checks if a number is a prime number[1] using the trial division method[2].
 *
 * [1]: https://en.wikipedia.org/wiki/Prime_number
 * [2]: https://en.wikipedia.org/wiki/Prime_number#Trial_division
 */
template <Integer T> bool is_prime(const T &n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (T i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }

  return true;
}

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

/**
 * Implemented in O(sqrt(n)) space via the segmented sieve of eratosthenes
 * algorithm[1].
 *
 * [1]:
 * https://cp-algorithms.com/algebra/sieve-of-eratosthenes.hpptml#segmented-sieve
 */
template <Integer T> std::vector<T> get_prime_factors(const T &n) {
  if (n <= 1)
    return std::vector<T>();
  if (is_prime(n))
    return std::vector<T>{n};

  std::vector<T> primes;
  if (n <= 8) {
    // sqrt(n) < 3
    if (n % 2 == 0)
      primes.push_back(2);
    if (n % 3 == 0)
      primes.push_back(3);

    return primes;
  }

  T n_sqrt = sqrt(n);
  std::vector<bool> is_prime(n_sqrt + 2, true);

  for (const T &i : std::ranges::views::iota((T)2, (T)(n_sqrt + 1))) {
    if (is_prime[i]) {
      if (n % i == 0) {
        primes.push_back(i);
      }
      for (T j = i * i; j <= n_sqrt; j += i) {
        is_prime[j] = false;
      }
    }
  };

  return primes;
}

/**
 * Gets all the prime fractors from the `get_prime_factors` function and prints
 * them to `stdout`.
 */
template <Integer T> std::vector<T> print_prime_factors(const T &n) {
  std::vector<T> nums = get_prime_factors(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

#endif // !UTILS_PRIMES_HPP
