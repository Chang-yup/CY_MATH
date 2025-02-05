#pragma once
#include <iostream>

#include "type.h"

namespace cy {
	//// ½ºÄ®¶ó ¿¬»ê
	//º¤ÅÍ µ¡¼À
	template<typename T>
	Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
		if(a.dimension != b.dimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;
		
		Vector<T> temp;

		for (size_t i = 0; i < a.dimension; i++) {
			temp.mData.push_back(a.mData[i] + b.mData[i]);
		}

		return temp;
	}
	template<typename T>
	Vector<T> operator+(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp;

		for (size_t i = 0; i < vec.dimension; i++) {
			temp.mData.push_back(vec.mData[i] + scalar);
		}

		return temp;
	}
	template<typename T>
	Vector<T> operator+(const T& scalar, const Vector<T>& vec) { return vec+scalar; }

	//º¤ÅÍ »¬¼À
	template<typename T>
	Vector<T> operator-(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp;

		for (size_t i = 0; i < vec.dimension; i++) {
			temp.mData.push_back(vec.mData[i] - scalar);
		}

		return temp;
	}

	template<typename T>
	Vector<T> operator-(const T& scalar, const Vector<T>& vec) {

		Vector<T> temp;

		for (size_t i = 0; i < vec.dimension; i++) {
			temp.mData.push_back(scalar - vec.mData[i]);
		}

		return temp;
	}

	//º¤ÅÍ °ö¼À(½ºÄ®¶ó°ö)
	template<typename T>
	Vector<T> operator*(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp;

		for (size_t i = 0; i < vec.dimension; i++) {
			temp.mData.push_back(vec.mData[i] * scalar);
		}

		return temp;
	}
	template<typename T>
	Vector<T> operator*(const T& scalar, const Vector<T>& vec) { return vec*scalar; }

	//// ºñ±³¿¬»ê
	template<typename T>
	Vector<T>& Vector<T>::operator+=(const T& scalar) {
		for (size_t i = 0; i < (*this).mDimension; i++) {
			mData[i] += scalar;
		}

		return (*this);
	}

	template<typename T>
	Vector<T>& Vector<T>::operator-=(const T& scalar) {
		for (size_t i = 0; i < (*this).mDimension; i++) {
			mData[i] -= scalar;
		}

		return (*this);
	}

	template<typename T>
	Vector<T>& Vector<T>::operator*=(const T& scalar) {
		for (size_t i = 0; i < (*this).mDimension; i++) {
			mData[i] *= scalar;
		}

		return (*this);
	}

	//// º¤ÅÍ¿¬»ê
	template<typename T>
	T dot(const Vector<T>& a, const Vector<T>& b) {
		if (a.dimension != b.dimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		T temp = 0;
		for (size_t i = 0; i < a.dimension; i++) {
			temp += a[i] * b[i];
		}

		return temp;
	}

	template<typename T>
	bool Vector<T>::operator==(const Vector<T>& other) {
		if ((*this).dimension != other.dimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		for (size_t i = 0; i < (*this).mDimension; i++) {
			if ((*this).mData[i] != other.mData[i]) return false;
		}
		return true;
	}

	template<typename T>
	bool Vector<T>::operator!=(const Vector<T>& other) {
		if ((*this).dimension != other.dimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		for (size_t i = 0; i < (*this).mDimension; i++) {
			if ((*this).mData[i] != other.mData[i]) return true;
		}
		return false;
	}

	template<typename T>
	bool Vector<T>::operator>(const Vector<T>& other) {
		return (*this).norm() > other.norm();
	}

	template<typename T>
	bool Vector<T>::operator<(const Vector<T>& other) {
		return (*this).norm() < other.norm();
	}

	template<typename T>
	bool Vector<T>::operator>=(const Vector<T>& other) {
		return (*this).norm() >= other.norm();
	}

	template<typename T>
	bool Vector<T>::operator<=(const Vector<T>& other) {
		return (*this).norm() <= other.norm();
	}

	////±âÅ¸¿¬»ê
	template<typename T>
	T Vector<T>::norm() {
		T temp = 0;
		for (size_t i = 0; i < (*this).dimension; i++) {
			temp += (*this).mData[i] * (*this).mData[i];
		}
		
		return static_cast<T>sqrt(static_cast<double>temp);
	}

	template<typename T>
	T getDist(const Vector<T>& a, const Vector<T>& b) {
		if (a.dimension != b.dimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		T temp1 = 0;
		for (size_t i = 0; i < a.dimension; i++) {
			T temp2 = a.mData[i] - b.mData[i];
			temp1 += temp2 * temp2;
		}

		return static_cast<T>sqrt(static_cast<double>temp1);
	}

}