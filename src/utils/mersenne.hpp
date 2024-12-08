#ifndef UTILS_MERSENNE_HPP
#define UTILS_MERSENNE_HPP

#include "./primes.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

/**
 * Check if a number is a mersenne number.
 * The mersenne form is M(n) = 2^n - 1.[1]
 *
 * NOTE: without necessarily checking for primeness.
 *
 * [1]: https://en.wikipedia.org/wiki/Mersenne_prime
 */
template <Integer T> bool is_mersenne(const T &n) {
  return n >= 0 && ((n + 1) & n) == 0;
}

// -----------------------------------------------------------------------------
// Task 2
// -----------------------------------------------------------------------------

/**
 * Checks if a number is a mersenne prime[1].
 *
 * Under the hood this is just a wrapper that returns `is_prime()` &&
 * `is_mersenne()`.
 *
 * [1]: https://en.wikipedia.org/wiki/Mersenne_prime
 */
template <Integer T> bool is_mersenne_prime(const T &n) {
  return is_mersenne(n) && is_prime(n);
}

// -----------------------------------------------------------------------------
// Task 6
// -----------------------------------------------------------------------------

// NOTE: Implementation is done in a different place due to depending on a
// different function.

/**
 * Prints all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin, const T &end);

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

/**
 * Getsthe first `n` amount of mersenne numbers.
 */
template <Integer T>
std::vector<T> get_first_n_amount_of_mersenne_nums(const T &n) {
  std::vector<T> res;
  if (n < 2)
    return res;

  T counter = 0;
  for (unsigned long long i = 0b11; counter < n; i = (i << 1) + 1, counter++) {
    res.push_back(i);
  }

  return res;
}

/**
 * Prints the first `n` amount of mersenne numbers.
 */
template <Integer T>
std::vector<T> print_first_n_amount_of_mersenne_nums(const T &n) {
  std::vector<T> nums = get_first_n_amount_of_mersenne_nums(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

/**
 * Gets the first `n` amount of mersenne prime numbers.
 */
template <Integer T>
std::vector<T> get_first_n_amount_of_mersenne_prime_nums(const T &n) {
  std::vector<T> res;

  T counter = 0;

  for (T i = 0b11; counter != n; i = (i << 1) + 1) {
    if (is_prime(i)) {
      res.push_back(i);
      counter++;
    }
  }

  return res;
}

/**
 * Prints the first `n` amount of mersenne prime numbers.
 */
template <Integer T>
std::vector<T> print_first_n_amount_of_mersenne_prime_nums(const T &n) {
  std::vector<T> nums = get_first_n_amount_of_mersenne_prime_nums(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 9
// -----------------------------------------------------------------------------

/**
 * Prints all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> get_mersenne_nums_in_interval(const T &begin, const T &end) {
  std::vector<T> res;

  if (end < begin)
    return res;

  for (T i = 0b11; i < end; i = (i << 1) + 1) {
    if (i < begin)
      continue;
    res.push_back(i);
  }

  return res;
}

/**
 * Gets all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin, const T &end) {
  std::vector<T> nums = get_mersenne_nums_in_interval(begin, end);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

#endif // !UTILS_MERSENNE_HPP
