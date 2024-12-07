#ifndef UTILS_PRIMES_CPP
#define UTILS_PRIMES_CPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
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

#endif // !UTILS_PRIMES_CPP
