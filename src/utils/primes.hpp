#ifndef UTILS_PRIMES_HPP
#define UTILS_PRIMES_HPP

#include "concepts.hpp"
#include <cmath>
#include <functional>
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
 * Applies a callback function `f` to all the prime factors of a number: `n`.
 *
 * ---
 *
 * Implemented in O(sqrt(n)) space via the segmented sieve of eratosthenes
 * algorithm[1].
 *
 * [1]:
 * https://cp-algorithms.com/algebra/sieve-of-eratosthenes.hpptml#segmented-sieve
 */
template <Integer T>
void operate_on_prime_factors(const T &n, std::function<void(const T &)> f) {
  if (n <= 1)
    return;

  if (is_prime(n)) {
    f(n);
    return;
  }

  if (n <= 8) {
    // sqrt(n) < 3
    if (n % 2 == 0)
      f(2);
    if (n % 3 == 0)
      f(3);

    return;
  }

  T n_sqrt = static_cast<T>(std::sqrt(n));
  std::vector<bool> is_prime(n_sqrt + 2, true);

  for (const T &i : std::ranges::views::iota(static_cast<T>(2), n_sqrt + 1)) {
    if (is_prime[i]) {
      if (n % i == 0) {
        f(i);
      }
      for (T j = i * i; j <= n_sqrt; j += i) {
        is_prime[j] = false;
      }
    }
  };

  return;
}

/**
 * Returns all the prime factors of a number: `n` in a vector.
 */
template <Integer T> std::vector<T> get_prime_factors(const T &n) {
  std::vector<T> primes;

  operate_on_prime_factors(
      n, std::function<void(const T &)>(
             [&primes](const T &prime) { primes.push_back(prime); }));

  return primes;
}

/**
 * Prints all the prime factors of a number: `n` in a vector.
 */
template <Integer T> void print_prime_factors(const T &n) {
  std::cout << "{ ";
  operate_on_prime_factors(n,
                           std::function<void(const T &)>([](const T &prime) {
                             std::cout << prime << " ";
                           }));
  std::cout << "}" << std::endl;

  return;
}

#endif // !UTILS_PRIMES_HPP
