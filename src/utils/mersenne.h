#ifndef UTILS_MERSENNE_H
#define UTILS_MERSENNE_H

#include "./concepts.h"

#include <functional>
#include <ranges>
#include <set>
#include <type_traits>
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
template <Integer T> bool is_mersenne(const T &n);

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
template <Integer T> bool is_mersenne_prime(const T &n);

// -----------------------------------------------------------------------------
// Task 6
// -----------------------------------------------------------------------------

/**
 * Prints all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin = 2,
                                               const T &end = 3);

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

/**
 * Gets the first `n` amount of mersenne numbers.
 */
template <Integer T>
std::vector<T> get_first_n_amount_of_mersenne_nums(const T &n);

/**
 * Prints the first `n` amount of mersenne numbers.
 */
template <Integer T>
std::vector<T> print_first_n_amount_of_mersenne_nums(const T &n);

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

/**
 * Gets the first `n` amount of mersenne prime numbers.
 */
template <Integer T>
std::vector<T> get_first_n_amount_of_mersenne_prime_nums(const T &n);

/**
 * Prints the first `n` amount of mersenne prime numbers.
 */
template <Integer T>
std::vector<T> print_first_n_amount_of_mersenne_prime_nums(const T &n);

// -----------------------------------------------------------------------------
// Task 9
//
// NOTE: Also used in order to print the mersenne numbers in task 6.
//
// -----------------------------------------------------------------------------

/**
 * Gets all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> get_mersenne_nums_in_interval(const T &begin = 2,
                                             const T &end = 3);

#endif // !UTILS_MERSENNE_H
