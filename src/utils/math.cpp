#include "math.h"
#include "helper_functions.cpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
#include <iostream>
#include <set>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

template <typename T, typename> bool is_mersenne(const T &n) {
  return n >= 0 && ((n + 1) & n) == 0;
}

// -----------------------------------------------------------------------------
// Task 2
// -----------------------------------------------------------------------------

/**
 * Implementation is done via the trial division method in order to save space.
 */
template <typename T, typename> bool is_prime(const T &n) {
  if (n <= 1)
    return false;

  for (T i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }

  return true;
}

template <typename T, typename> bool is_mersenne_prime(const T &n) {
  return is_prime(n) && is_mersenne(n);
}

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

template <typename T, typename> void print_divisors(const T &n) {
  if (n <= 1)
    return;

  for (T i = 2; i < n; i++)
    if (n % i == 0)
      printf("%d\n", i);

  return;
}

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

template <typename T, typename> std::vector<T> get_prime_factors(const T &n) {
  T n_sqrt = sqrt(n);
  std::vector<bool> is_prime(n_sqrt + 2, true);
  std::vector<T> primes;

  for (T i = 2; i <= n_sqrt; i++) {
    if (is_prime[i]) {
      if (n % i == 0) {
        primes.push_back(i);
      }
      for (T j = i * i; j <= n_sqrt; j += i) {
        is_prime[j] = false;
      }
    }
  }

  return primes;
}

template <typename T, typename> void print_prime_factors(const T &n) {
  if (n <= 1)
    return;

  T digit_count = 0;
  {
    T tmp = n;
    for (; tmp > 10; tmp /= 10)
      digit_count++;
  }

  std::vector<T> primes = get_prime_factors(n);

  for (const T prime : primes)
    std::cout << prime << " ";

  std::cout << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

template <typename T, typename>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b) {
  std::set<T> res;

  for (const T &item : a)
    if (b.find(item) == b.end())
      res.insert(item);

  return res;
}

template <typename T, typename>
std::vector<T> vec_difference(const std::set<T> &a, const std::set<T> &b) {
  std::vector<T> res(a.size());
  typename std::vector<T>::iterator it;

  it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());

  res.resize(it - res.begin());

  return res;
}

template <typename T, typename>
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

template <typename T, typename>
void print_mersenne_nums_in_interval(const T &begin, const T &end) {
  if (begin <= 0 || end < begin)
    return;

  std::cout << "{ ";
  for (T i = begin; i <= end; i++) {
    if (is_mersenne_prime(i)) {
      std::cout << i << " ";
    }
  }
  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

template <typename T, typename>
void print_first_n_amount_of_mersenne_nums(T n) {
  T counter = 0;
  if (n < 2)
    return;
  if (n == 2)
    std::cout << "{ " << 2 << " }" << std::endl;

  std::cout << "{ ";
  for (unsigned long long i = 0b11; counter < n; i = (i << 1) + 1) {
    std::cout << i << " ";
    counter++;
  }
  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

template <typename T, typename>
void print_first_n_amount_of_mersenne_prime_nums(T n) {
  T counter = 0;
  std::cout << "{ ";
  for (unsigned long long i = 0b11; counter != n; i = (i << 1) + 1) {
    if (is_prime(i)) {
      std::cout << i << " ";
      counter++;
    }
  }
  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 9
// -----------------------------------------------------------------------------

template <typename T, typename>
std::vector<T> get_mersenne_nums_from_interval(const T &begin, const T &end) {
  std::vector<T> res;

  if (begin > end || end <= 2)
    return res;

  // Skip even numbers.

  T new_begin = begin;
  if (begin % 2 == 0)
    new_begin = begin + 1;
  if (begin <= 2)
    new_begin = 3;

  for (int i = new_begin; i <= end; i += 1) {
    if (is_mersenne(i)) {
      res.push_back(i);
    }
  }

  return res;
}

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

template <typename T, typename> bool is_perfect(T n) {
  // Credit: https://www.geeksforgeeks.org/perfect-number/

  if (n <= 1)
    return false;

  unsigned long long sum = 1;

  for (unsigned long long i = 2; i * i < n; i++) {
    if (n % i == 0) {
      ((i * i) != n) ? (sum += i + (n / i)) : (sum += i);
    }
  }

  return sum == n;
}

template <typename T, typename>
std::vector<T> get_perfect_nums_from_interval(const T &begin, const T &end) {
  std::vector<T> res;
  if (begin > end)
    return res;

  if (end < 6)
    return res;

  res.push_back(6);

  if (end < 28)
    return res;

  res.push_back(28);

  T new_begin = begin;
  if (begin < 29)
    new_begin = 29;

  for (int i = new_begin; i <= end; i++) {
    if (is_perfect(i)) {
      res.push_back(i);
    }
  }

  return res;
}
