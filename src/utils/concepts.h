#ifndef UTILS_CONCEPTS_H
#define UTILS_CONCEPTS_H

#include <type_traits>

template <typename T>
concept Integer = std::enable_if<std::is_arithmetic_v<T>, T>::type;

#endif // !UTILS_CONCEPTS_H
