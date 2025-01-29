#pragma once
#include <type_traits>

template<typename T, typename U>
void linearRegression(T& resultA, T& resultB, const U& x, const U& y);

#include "my_math.hpp"