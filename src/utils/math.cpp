#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

template <typename T> bool is_mersenne(const T &n) {
  return n >= 0 && ((n + 1) & n) == 0;
}

// -----------------------------------------------------------------------------
// Task 2
// -----------------------------------------------------------------------------

/**
 * Implementation is done via the trial division method in order to save space.
 */
template <typename T> bool is_prime(const T &n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (T i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }

  return true;
}

template <typename T> bool is_mersenne_prime(const T &n) {
  return is_prime(n) && is_mersenne(n);
}

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

template <typename T> std::vector<T> get_divisors(const T &n) {
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

template <typename T> std::vector<T> print_divisors(const T &n) {
  std::vector<T> nums = get_divisors(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << " }" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

template <typename T> std::vector<T> get_prime_factors(const T &n) {
  if (n <= 1)
    return std::vector<T>();
  if (is_prime(n))
    return std::vector<T>{n};

  std::vector<T> primes;
  if (n <= 8) {
    // sqrt(n) < 3
    if (n % 2 == 0)
      primes.push_back(2);
    if (n % 3 == 0)
      primes.push_back(3);

    return primes;
  }

  T n_sqrt = sqrt(n);
  std::vector<bool> is_prime(n_sqrt + 2, true);

  for (const T &i : std::ranges::views::iota((T)2, (T)(n_sqrt + 1))) {
    if (is_prime[i]) {
      if (n % i == 0) {
        primes.push_back(i);
      }
      for (T j = i * i; j <= n_sqrt; j += i) {
        is_prime[j] = false;
      }
    }
  };

  return primes;
}

template <typename T> std::vector<T> print_prime_factors(const T &n) {
  std::vector<T> nums = get_prime_factors(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

template <typename T>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b) {
  std::set<T> res;

  std::function<bool(const T)> not_in_b = [b](const T &item) {
    return b.find(item) == b.end();
  };

  for (const T &item : a | std::ranges::views::filter(not_in_b))
    res.insert(item);

  return res;
}

template <typename T>
std::vector<T> vec_difference(const std::set<T> &a, const std::set<T> &b) {
  std::vector<T> res(a.size());
  typename std::vector<T>::iterator it;

  it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());

  res.resize(it - res.begin());

  return res;
}

template <typename T>
std::vector<T> vec_difference(const std::vector<T> &a,
                              const std::vector<T> &b) {
  std::vector<T> res(a.size());
  typename std::vector<T>::iterator it;

  it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());

  res.resize(it - res.begin());

  return res;
}

// -----------------------------------------------------------------------------
// Task 6
// -----------------------------------------------------------------------------

// NOTE: Implementation is done in a different place due to depending on a
// different function.
template <typename T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin, const T &end);

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

template <typename T>
std::vector<T> get_first_n_amount_of_mersenne_nums(const T &n) {
  std::vector<T> res;
  if (n < 2)
    return res;

  T counter = 0;
  for (unsigned long long i = 0b11; counter < n; i = (i << 1) + 1, counter++) {
    res.push_back(i);
  }

  return res;
}

template <typename T>
std::vector<T> print_first_n_amount_of_mersenne_nums(const T &n) {
  std::vector<T> nums = get_first_n_amount_of_mersenne_nums(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

template <typename T>
std::vector<T> get_first_n_amount_of_mersenne_prime_nums(const T &n) {
  std::vector<T> res;

  if (n < 2)
    return res;

  T counter = 0;

  for (unsigned long long i = 0b11; counter != n; i = (i << 1) + 1) {
    if (is_prime(i)) {
      res.push_back(i);
      counter++;
    }
  }

  return res;
}

template <typename T>
std::vector<T> print_first_n_amount_of_mersenne_prime_nums(const T &n) {
  std::vector<T> nums = get_first_n_amount_of_mersenne_prime_nums(n);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

// -----------------------------------------------------------------------------
// Task 9
// -----------------------------------------------------------------------------

template <typename T>
std::vector<T> get_mersenne_nums_in_interval(const T &begin, const T &end) {
  std::vector<T> res;

  if (end < begin)
    return res;

  for (T i = 0b11; i < end; i = (i << 1) + 1) {
    if (i < begin)
      continue;
    res.push_back(i);
  }

  return res;
}

template <typename T>
std::vector<T> print_mersenne_nums_in_interval(const T &begin, const T &end) {
  std::vector<T> nums = get_mersenne_nums_in_interval(begin, end);

  std::cout << "{ ";
  std::ranges::for_each(nums, [](const T &num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;

  return nums;
}

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
  for (const T &i
       : range
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
