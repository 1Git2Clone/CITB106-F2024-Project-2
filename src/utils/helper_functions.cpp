#include "helper_functions.h"
#include <iostream>

void print_heading(const std::string &content) {
  std::string lines(content.size(), '-');
  std::cout << lines.c_str() << std::endl;
  std::cout << content << std::endl;
  std::cout << lines.c_str() << std::endl;
}

void print_heading(const char **content) {
  std::string lines(sizeof(content) / sizeof(char), '-');
  printf("%s\n%s\n%s", lines.c_str(), *content, lines.c_str());
}

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
