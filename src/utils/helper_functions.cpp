#include "helper_functions.h"
#include <iostream>

template <typename T> bool binary_search(T val, const std::vector<T> &from) {
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

template <typename T> void print_vec(const std::vector<T> &v) {
  std::cout << "{ ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <typename T> void print_vec(const std::vector<T> &v, const char *msg) {
  std::cout << msg << ": { ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <typename T> void print_set(const std::set<T> &v) {
  std::cout << "{ ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}

template <typename T> void print_set(const std::set<T> &v, const char *msg) {
  std::cout << msg << ": { ";
  for (const T &i : v)
    std::cout << i << " ";
  std::cout << "}" << std::endl;
}
