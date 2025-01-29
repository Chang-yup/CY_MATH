#include <iostream>
#include "error_check.h"

// linear regression
template<typename T, typename U>
void linearRegression(T& resultA, T& resultB, const U& x, const U& y) {
	// COMPILE TIME ERROR CHECK
	CHECK_DT_FRACTION(T);
	CHECK_MT_SIZE(U);
	CHECK_MT_AT(U);

	// RUN TIME ERROR CHECK
	if (x.size() != y.size()) std::cerr << "[ERROR] The size of containers are not equal." << std::endl;
	if (x.size() < 2) std::cerr << "[ERROR] The size must be larger than one" << std::endl;

	// LINEAR REGRESSION
	size_t n = x.size();

	T sumX = 0, sumY = 0;
	T avgX = 0, avgY = 0;
	for (size_t i = 0; i < n; i++) {
		T curX = x.at(i);
		T curY = y.at(i);

		sumX += curX;
		sumY += curY;

	}

	avgX = sumX / n;
	avgY = sumY / n;

	T temp1 = 0, temp2 = 0;
	for (size_t i = 0; i < n; i++) {
		T curX = x.at(i);
		T curY = y.at(i);
		T devX = (curX - avgX);
		T devY = (curY - avgY);

		temp1 += devX * devY;
		temp2 += devX * devX;

	}

	if (temp2 == 0) std::cout << "[WARNING] The sum of squared deviation X is zero." << std::endl;
	resultA = temp1 / temp2;
	resultB = avgY - (resultA * avgX);
}