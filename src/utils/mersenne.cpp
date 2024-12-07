#ifndef UTILS_MERSENNE_CPP
#define UTILS_MERSENNE_CPP

#include "./primes.cpp"

#include <algorithm>
#include <cmath>
#include <iostream>
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

template <typename T> bool is_mersenne_prime(const T &n) {
  return is_prime(n) && is_mersenne(n);
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

#endif // !UTILS_MERSENNE_CPP
