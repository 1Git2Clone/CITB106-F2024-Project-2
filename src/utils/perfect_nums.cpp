#ifndef UTILS_PERFECT_NUMS_CPP
#define UTILS_PERFECT_NUMS_CPP

#include <cmath>
#include <functional>
#include <ranges>
#include <vector>

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

template <typename T> bool is_perfect(const T &n) {
  // Credit: https://www.geeksforgeeks.org/perfect-number/

  if (n <= 5)
    return false;

  unsigned long long sum = 1;

  for (unsigned long long i = 2; i * i < n; i++) {
    if (n % i == 0) {
      ((i * i) != n) ? (sum += i + (n / i)) : (sum += i);
    }
  }

  return sum == n;
}

template <typename T>
std::vector<T>
get_perfect_nums_in_range(const std::ranges::iota_view<T, T> &range) {
  std::vector<T> res;
  T end = *std::ranges::prev(range.end());

  if (end < 6)
    return res;

  std::function<bool(const T)> is_perfect_n = [](const T &n) {
    return is_perfect(n);
  };

  // clang-format off
  for (const T &i : range
                  | std::ranges::views::filter(is_perfect_n)) {
    res.push_back(i);
  }
  // clang-format on

  return res;

  return res;
}

template <typename T>
std::vector<T> get_perfect_nums_in_interval(const T &begin, const T &end) {
  if (begin > end || end < 6)
    return std::vector<T>{};

  std::ranges::iota_view<T, T> range =
      std::ranges::views::iota(begin, (T)(end));
  return get_perfect_nums_in_range(range);
}

#endif // !UTILS_PERFECT_NUMS_CPP