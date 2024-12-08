#ifndef HELPER_FUNCTIONS_HPP
#define HELPER_FUNCTIONS_HPP

#include "concepts.hpp"

#include <iostream>
#include <limits>
#include <set>
#include <type_traits>
#include <vector>

template <Integer T> bool binary_search(T val, const std::vector<T> &from) {
  int min = 0;
  int max = from.size() - 1;

  while (max < min) {
    int mid = (max + min) / 2;
    if (from[mid] == val) {
      return true;
    } else if (from[mid] < val) {
      min = mid;
    } else {
      max = mid;
    }
  }

  return false;
};

template <Integer T> void print_vec(const std::vector<T> &v) {
  std::cout << "{ ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <Integer T> void print_vec(const std::vector<T> &v, const char *msg) {
  std::cout << msg << ": { ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <Integer T> void print_set(const std::set<T> &v) {
  std::cout << "{ ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <Integer T> void print_set(const std::set<T> &v, const char *msg) {
  std::cout << msg << ": { ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <Integer T>
// Weird behaviour for unsigned ints with negative input (doesn't trigger
// `std::cin.fail()`).
  requires std::is_signed_v<T>
T get_integer_input_line(const std::string &msg,
                         const T &min = std::numeric_limits<T>::min(),
                         const T &max = std::numeric_limits<T>::max()) {
  T input;
  while (true) {
    std::cout << msg;
    std::cin >> input;

    if (std::cin.eof())
      exit(1);

    if (std::cin.fail()) {
      std::cout << "Invalid input." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (input < min) {
      std::cout << "Input was less than " << min << ". Defaulting to " << min
                << std::endl;
      input = min;
    }
    if (input > max) {
      std::cout << "Input was greater than " << max << ". Defaulting to " << max
                << std::endl;
      input = max;
    }

    break;
  };

  return input;
}

#endif // !HELPER_FUNCTIONS_HPP
