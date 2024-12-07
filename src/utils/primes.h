#ifndef UTILS_PRIMES_H
#define UTILS_PRIMES_H

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
 * Checks if a number is a prime number[1] using the trial division method[2].
 *
 * [1]: https://en.wikipedia.org/wiki/Prime_number
 * [2]: https://en.wikipedia.org/wiki/Prime_number#Trial_division
 */
template <Integer T> bool is_prime(const T &n);

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

#endif // !UTILS_PRIMES_H
