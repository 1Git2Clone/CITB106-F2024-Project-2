#ifndef UTILS_CONCEPTS_HPP
#define UTILS_CONCEPTS_HPP

#include <type_traits>

template <typename T>
concept Integer = std::is_arithmetic_v<T>;

#endif // !UTILS_CONCEPTS_HPP
