#ifndef UTILS_PERFECT_NUMS_H
#define UTILS_PERFECT_NUMS_H

#include "./concepts.h"

#include <functional>
#include <ranges>
#include <set>
#include <type_traits>
#include <vector>

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
get_perfect_nums_in_range(const std::ranges::iota_view<T, T> &range);

/**
 * Gets all the perfect numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> get_perfect_nums_in_interval(const T &begin = 6,
                                            const T &end = 7);

#endif // !UTILS_PERFECT_NUMS_H
