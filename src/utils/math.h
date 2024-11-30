#ifndef UTILS_MATH_H
#define UTILS_MATH_H

#include <functional>
#include <set>
#include <type_traits>
#include <vector>

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
bool is_mersenne(const T &n);

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
bool is_prime(const T &n);

// -----------------------------------------------------------------------------
// Task 2
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
bool is_mersenne_prime(const T &n);

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
void print_divisors(const T &n);

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

/**
 * Implemented in O(sqrt(n)) space via the segmented sieve of eratosthenes
 * algorithm[1].
 *
 * [1]:
 * https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::vector<T> get_prime_factors(const T &n);

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
void print_prime_factors(const T &n);

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b);

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::vector<T> vec_difference(const std::set<T> &a, const std::set<T> &b);

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::vector<T> vec_difference(const std::vector<T> &a, const std::vector<T> &b);

// -----------------------------------------------------------------------------
// Task 6
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
void print_mersenne_nums_in_interval(const T &begin = 2, const T &end = 2);

// -----------------------------------------------------------------------------
// Task 7
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
void print_first_n_amount_of_mersenne_nums(T n);

// -----------------------------------------------------------------------------
// Task 8
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
void print_first_n_amount_of_mersenne_prime_nums(T n);

// -----------------------------------------------------------------------------
// Task 9
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::vector<T> get_mersenne_nums_from_interval(const T &begin = 2,
                                               const T &end = 2);

// -----------------------------------------------------------------------------
// Task 10
// -----------------------------------------------------------------------------

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
bool is_perfect(T n);

/**
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::vector<T> get_perfect_nums_from_interval(const T &begin = 6,
                                              const T &end = 6);

#endif // !UTILS_MATH_H
