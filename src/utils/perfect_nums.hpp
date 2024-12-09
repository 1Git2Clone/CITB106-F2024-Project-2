#ifndef UTILS_PERFECT_NUMS_HPP
#define UTILS_PERFECT_NUMS_HPP
#include "./concepts.hpp"

#include <cmath>
#include <ranges>
#include <vector>

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

/**
 * Checks if a number is a perfect number.
 */
template <Integer T> bool is_perfect(const T &n) {
  // Credit: https://www.geeksforgeeks.org/perfect-number/

  if (n <= 5)
    return false;

  T sum = 1;

  for (T i = 2; i * i < n; i++) {
    if (n % i == 0) {
      ((i * i) != n) ? (sum += i + (n / i)) : (sum += i);
    }
  }

  return sum == n;
}

/**
 * Gets all the perfect numbers from an `std::ranges::iota_view`.
 */
template <Integer T>
std::vector<T>
get_perfect_nums_in_range(const std::ranges::iota_view<T, T> &range) {
  T end = *std::ranges::prev(range.end());
  if (end < 6)
    return std::vector<T>{};

  T begin = *std::ranges::prev(range.begin());
  if (end < begin)
    return std::vector<T>{};

  return std::ranges::to<std::vector<T>>(
      range |
      std::ranges::views::filter([](const T &n) { return is_perfect(n); }));
}

/**
 * Gets all the perfect numbers from `begin` to `end`.
 */
template <Integer T>
std::vector<T> get_perfect_nums_in_interval(const T &begin, const T &end) {
  return get_perfect_nums_in_range(std::ranges::views::iota(begin, end));
}

#endif // !UTILS_PERFECT_NUMS_HPP
