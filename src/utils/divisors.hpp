#ifndef UTILS_DIVISORS_HPP
#define UTILS_DIVISORS_HPP

#include "./concepts.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <ranges>

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

/**
 * Gets all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> get_divisors(const T &n) {
  std::vector<T> res;
  if (n <= 1)
    return res;

  std::function<bool(const T)> div_by_i = [n](const T &i) {
    return n % i == 0;
  };

  // clang-format off
  //
  // For reference[1].
  // NOTE: This is the formatting they use in the official documentation[2].
  //
  // [1]: https://stackoverflow.com/questions/70942638/tweaking-clang-format-for-c20-ranges-pipelines/75283554#75283554
  // [2]: https://en.cppreference.com/w/cpp/ranges/filter_view#Example
  for (const T &i : std::ranges::views::iota((T)2, (T)n)
                  | std::ranges::views::filter(div_by_i)) {
    res.push_back(i);
  }
  // clang-format on

  return res;
}

/**
 * Prints all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> print_divisors(const T &n) {
  std::vector<T> nums = get_divisors(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << " }" << std::endl;

  return nums;
}

#endif // !UTILS_DIVISORS_HPP
