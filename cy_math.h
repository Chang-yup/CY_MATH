#pragma once
#include <type_traits>
#include <ctime>
#include <random>

#include "class\cy_interface.h"

template<typename T, typename U>
void linearRegression(T& resultA, T& resultB, const Container<T, U>& x, const Container<T, U>& y);

template<typename T>
class RandomGenerator {
public:
	RandomGenerator() : rng(std::random_device{}()) {}

	T uniform(T min, T max) {
		std::uniform_real_distribution<double> dist(min, max);
		return dist(rng);
	}

	T normal(T mean, T stddev) {
		std::normal_distribution<double> dist(mean, stddev);
		return dist(rng);
	}

private:
	std::mt19937 rng; // Mersenne Twister 19937 ¿£Áø
};

#include "cy_math.hpp"