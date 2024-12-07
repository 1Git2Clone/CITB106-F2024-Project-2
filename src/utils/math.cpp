#include "math.h"

#include <algorithm>
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
  if (begin <= 1 || end < begin)
    return;
  std::vector<T> nums = get_mersenne_nums_in_interval(begin, end);

  std::cout << "{ ";
  for (const T &num : nums) {
    std::cout << num << " ";
  }
  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

template <typename T, typename>
std::vector<T> get_first_n_amount_of_mersenne_nums(T n) {
  std::vector<T> res;
  if (n < 2)
    return res;

  res.push_back(2);
  T counter = 0;
  for (unsigned long long i = 0b11; counter <= n; i = (i << 1) + 1, counter++) {
    res.push_back(i);
  }

  return res;
}

template <typename T, typename>
void print_first_n_amount_of_mersenne_nums(T n) {
  std::cout << "{ " << 2 << " ";
  std::vector<T> nums = get_first_n_amount_of_mersenne_nums(n);

  for (const T &num : nums) {
    std::cout << num << " ";
  }

  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

template <typename T, typename>
std::vector<T> get_first_n_amount_of_mersenne_prime_nums(T n) {
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

template <typename T, typename>
void print_first_n_amount_of_mersenne_prime_nums(T n) {
  std::vector<T> nums = get_first_n_amount_of_mersenne_prime_nums(n);

  std::cout << "{ ";
  for (const T &num : nums) {
    std::cout << num << " ";
  }
  std::cout << "}" << std::endl;

  return;
}

// -----------------------------------------------------------------------------
// Task 9
// -----------------------------------------------------------------------------

template <typename T, typename>
std::vector<T> get_mersenne_nums_in_interval(const T &begin, const T &end) {
  std::vector<T> res;

  if (begin <= 1 || end < begin)
    return res;

  res.push_back(2);

  for (T i = 0b11; i <= end; i = (i << 1) + 1) {
    res.push_back(i);
  }

  return res;
}

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

template <typename T, typename> bool is_perfect(T n) {
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

template <typename T, typename>
std::vector<T> get_perfect_nums_from_interval(const T &begin, const T &end) {
  std::vector<T> res;
  if (begin > end)
    return res;

  if (end < 6)
    return res;

  res.push_back(6);

  T second_perfect_number = 28;
  if (end < second_perfect_number)
    return res;

  res.push_back(second_perfect_number);

  for (int i = second_perfect_number + 1; i <= end; i++) {
    if (is_perfect(i)) {
      res.push_back(i);
    }
  }

  return res;
}
