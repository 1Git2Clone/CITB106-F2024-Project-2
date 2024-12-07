#ifndef UTILS_DIVISORS_H
#define UTILS_DIVISORS_H

#include "./concepts.h"

#include <functional>
#include <ranges>
#include <set>
#include <type_traits>
#include <vector>

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

/**
 * Gets all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> get_divisors(const T &n);
/**
 * Prints all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> print_divisors(const T &n);

#endif // !UTILS_DIVISORS_H
