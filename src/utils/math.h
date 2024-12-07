#ifndef UTILS_MATH_H
#define UTILS_MATH_H

#include <functional>
#include <ranges>
#include <set>
#include <type_traits>
#include <vector>

template <typename T>
concept Integer = std::enable_if<std::is_arithmetic_v<T>, T>::type;

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

/**
 * Checks if a number is a prime number[1] using the trial division method[2].
 *
 * [1]: https://en.wikipedia.org/wiki/Prime_number
 * [2]: https://en.wikipedia.org/wiki/Prime_number#Trial_division
 */
template <Integer T> bool is_prime(const T &n);

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
// Task 3
// -----------------------------------------------------------------------------

/**
 * Prints all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> print_divisors(const T &n);

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

/**
 * Implemented in O(sqrt(n)) space via the segmented sieve of eratosthenes
 * algorithm[1].
 *
 * [1]:
 * https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve
 */
template <Integer T> std::vector<T> get_prime_factors(const T &n);

/**
 * Gets all the prime fractors from the `get_prime_factors` function and prints
 * them to `stdout`.
 */
template <Integer T> std::vector<T> print_prime_factors(const T &n);

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b);

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::vector<T> vec_difference(const std::set<T> &a, const std::set<T> &b);

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::vector<T> vec_difference(const std::vector<T> &a, const std::vector<T> &b);

// -----------------------------------------------------------------------------
// Task 6
// -----------------------------------------------------------------------------

/**
 * Prints all the non-prime mersene numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin = 2,
                                               const T &end = 2);

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
                                             const T &end = 2);

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

/**
 * Checks if a number is a perfect number.
 */
template <Integer T> bool is_perfect(const T &n);

/**
 * Gets all the perfect numbers from an `std::ranges::iota_view`.
 */
template <Integer T>
std::vector<T>
get_perfect_nums_from_range(const std::ranges::iota_view<T, T> &range);

/**
 * Gets all the perfect numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> get_perfect_nums_from_interval(const T &begin = 6,
                                              const T &end = 6);

#endif // !UTILS_MATH_H
