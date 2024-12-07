#ifndef UTILS_SET_MATH_H
#define UTILS_SET_MATH_H

#include "./concepts.h"

#include <functional>
#include <ranges>
#include <set>
#include <type_traits>
#include <vector>

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

#endif // !UTILS_SET_MATH_H
