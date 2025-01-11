#ifndef UTILS_DIVISORS_HPP
#define UTILS_DIVISORS_HPP

#include "./concepts.hpp"
#include "mersenne.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <ranges>

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

/**
 * Applies a callback function `f` to all the divisors of a number `n` that are
 * greater than `1` and less than `n`.
 */
template <Integer T>
void operate_on_divisors(const T &n, std::function<void(const T &)> f) {

  if (n <= 1 || is_mersenne_prime(n))
    return;

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
  for (const T &i : std::ranges::views::iota(static_cast<T>(2), static_cast<T>(n))
                  | std::ranges::views::filter(div_by_i)) {
    f(i);
  }
}

/**
 * Gets all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> std::vector<T> get_divisors(const T &n) {
  std::vector<T> res;

  operate_on_divisors(n, std::function<void (const T &)>([&res](const T&divisor){
    res.push_back(divisor);
  }));

  return res;
}

/**
 * Prints all the divisors of a number `n` that are greater than `1` and less
 * than `n`.
 */
template <Integer T> void print_divisors(const T &n) {
  std::cout << "{ ";
  operate_on_divisors(n, std::function<void (const T &)>([](const T&divisor){
    std::cout << divisor << " ";
  }));
  std::cout << "}" << std::endl;

  return;
}

#endif // !UTILS_DIVISORS_HPP
