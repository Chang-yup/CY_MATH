#pragma once
#include <type_traits>
#include "cy_interface.h"

template<typename T, typename U>
void linearRegression(T& resultA, T& resultB, const Container<T, U>& x, const Container<T, U>& y);

#include "cy_math.hpp"