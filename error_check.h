#pragma once
#include <type_traits>

// DT: Data Type, MT: Method

// check data type is fraction (float or double)
#define CHECK_DT_FRACTION(T) static_assert(std::is_same_v<std::decay_t<T>, float> || std::is_same_v<std::decay_t<T>, double>, "[ERROR] Type must be Float or Double.")

// check data type has 'size' method
template <typename T, typename = void>
struct has_size : std::false_type {};

template <typename T>
struct has_size<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

#define CHECK_MT_SIZE(T) static_assert(has_size<T>::value, "[ERROR] Type must have a 'size' method.")

// check data type has 'at(size_t n)' method
template <typename T, typename = void>
struct has_at : std::false_type {};

template <typename T>
struct has_at<T, std::void_t<decltype(std::declval<T>().at(std::declval<size_t>()))>> : std::true_type {};

#define CHECK_MT_AT(T) static_assert(has_at<T>::value, "[ERROR] Type must have an 'at(size_t)' method.")

// check data type has 'operator[]'
template <typename T, typename = void>
struct has_subscript : std::false_type {};

template <typename T>
struct has_subscript<T, std::void_t<decltype(std::declval<T>()[std::declval<size_t>()])>> : std::true_type {};

#define CHECK_OP_SUBSCRIPT(T) static_assert(has_subscript<T>::value, "[ERROR] Type must have 'operator[]'.")