#ifndef UTILS_SET_MATH_HPP
#define UTILS_SET_MATH_HPP

#include "./concepts.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <ranges>
#include <set>
#include <vector>

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b) {
  std::set<T> res;

  std::function<bool(const T)> not_in_b = [b](const T &item) {
    return b.find(item) == b.end();
  };

  for (const T &item : a | std::ranges::views::filter(not_in_b))
    res.insert(item);

  return res;
}

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::vector<T> vec_difference(const std::set<T> &a, const std::set<T> &b) {
  std::vector<T> res(a.size());
  typename std::vector<T>::iterator it;

  it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());

  res.resize(it - res.begin());

  return res;
}

/**
 * Equivalent of doing `A \ B` in set theory returning all the members of `A`
 * which don't exist in `B`.
 */
template <Integer T>
std::vector<T> vec_difference(const std::vector<T> &a,
                              const std::vector<T> &b) {
  std::vector<T> res(a.size());
  typename std::vector<T>::iterator it;

  it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());

  res.resize(it - res.begin());

  return res;
}

#endif // !UTILS_SET_MATH_HPP
