#ifndef UTILS_HELPER_FUNCTIONS_H
#define UTILS_HELPER_FUNCTIONS_H

#include <set>
#include <vector>

template <typename T> bool binary_search(T val, const std::vector<T> &from);
template <typename T> void print_vec(const std::vector<T> &v);
template <typename T> void print_vec(const std::vector<T> &v, const char *msg);

template <typename T> void print_set(const std::set<T> &v);
template <typename T> void print_set(const std::set<T> &v, const char *msg);

#endif // UTILS_HELPER_FUNCTIONS_H
