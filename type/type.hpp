#pragma once
#include <iostream>

#include "type.h"

namespace cy {
	//// ½ºÄ®¶ó ¿¬»ê
	//µ¡¼À
	template<typename T>
	Vector<T> operator+(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp(vec.mDimension, 0);

		for (size_t i = 0; i < vec.mDimension; i++) {
			temp.mData[i] = vec.mData[i] + scalar;
		}

		return temp;
	}
	template<typename T>
	Vector<T> operator+(const T& scalar, const Vector<T>& vec) { return vec+scalar; }

	//»¬¼À
	template<typename T>
	Vector<T> operator-(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp(vec.mDimension, 0);

		for (size_t i = 0; i < vec.mDimension; i++) {
			temp.mData[i] = vec.mData[i] - scalar;
		}

		return temp;
	}

	template<typename T>
	Vector<T> operator-(const T& scalar, const Vector<T>& vec) {

		Vector<T> temp(vec.mDimension, 0);

		for (size_t i = 0; i < vec.mDimension; i++) {
			temp.mData[i] = scalar - vec.mData[i];
		}

		return temp;
	}

	//°ö¼À(½ºÄ®¶ó°ö)
	template<typename T>
	Vector<T> operator*(const Vector<T>& vec, const T& scalar) {

		Vector<T> temp(vec.mDimension, 0);

		for (size_t i = 0; i < vec.mDimension; i++) {
			temp.mData[i] = vec.mData[i] * scalar;
		}

		return temp;
	}
	template<typename T>
	Vector<T> operator*(const T& scalar, const Vector<T>& vec) { return vec*scalar; }

	//// º¤ÅÍ¿¬»ê
	//´ëÀÔ¿¬»ê
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
	//ºñ±³¿¬»ê
	template<typename T>
	Vector<T>& Vector<T>::operator*=(const T& scalar) {
		for (size_t i = 0; i < (*this).mDimension; i++) {
			mData[i] *= scalar;
		}

		return (*this);
	}

	template<typename T>
	bool Vector<T>::operator==(const Vector<T>& other) {
		if ((*this).mDimension != other.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		for (size_t i = 0; i < (*this).mDimension; i++) {
			if ((*this).mData[i] != other.mData[i]) return false;
		}
		return true;
	}

	template<typename T>
	bool Vector<T>::operator!=(const Vector<T>& other) {
		if ((*this).mDimension != other.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

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

	//µ¡¼À
	template<typename T>
	Vector<T> Vector<T>::operator+(const Vector<T>& other) {
		if ((*this).mDimension != other.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		Vector<T> temp((*this).mDimension, 0);

		for (size_t i = 0; i < (*this).mDimension; i++) {
			temp.mData[i] = (*this).mData[i] + other.mData[i];
		}

		return temp;
	}
	//»¬¼À
	template<typename T>
	Vector<T> Vector<T>::operator-(const Vector<T>& other) {
		if ((*this).mDimension != other.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		Vector<T> temp((*this).mDimension, 0);

		for (size_t i = 0; i < (*this).mDimension; i++) {
			temp.mData[i] = (*this).mData[i] - other.mData[i];
		}

		return temp;
	}

	//³»Àû
	template<typename T>
	T dot(const Vector<T>& a, const Vector<T>& b) {
		if (a.mDimension != b.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		T temp = 0;
		for (size_t i = 0; i < a.mDimension; i++) {
			temp += a[i] * b[i];
		}

		return temp;
	}

	////±âÅ¸¿¬»ê
	template<typename T>
	T Vector<T>::norm() {
		T temp = 0;
		for (size_t i = 0; i < (*this).mDimension; i++) {
			temp += (*this).mData[i] * (*this).mData[i];
		}
		
		return static_cast<T>sqrt(static_cast<double>temp);
	}

	template<typename T>
	T getDist(const Vector<T>& a, const Vector<T>& b) {
		if (a.mDimension != b.mDimension) std::cerr << "[ERROR] The dimension of vectors are not equal." << std::endl;

		T temp1 = 0;
		for (size_t i = 0; i < a.mDimension; i++) {
			T temp2 = a.mData[i] - b.mData[i];
			temp1 += temp2 * temp2;
		}

		return static_cast<T>sqrt(static_cast<double>temp1);
	}

	template<typename T>
	void Vector<T>::set(size_t target_index, T data) {
		if (n >= mDimension) std::cerr << "The target index must be less than dimension!" << std::endl;

		mData[target_index] = data;
	}
	template<typename T>
	T Vector<T>::get(size_t target_index) {
		if (n >= mDimension) std::cerr << "The target index must be less than dimension!" << std::endl;

		return mData[target_index];
	}

	template<typename T>
	void Vector<T>::print() {
		for (size_t i = 0; i < (*this).mDimension; i++) {
			std::cout << (*this).mData[i] << " ";
		}
		std::cout << std::endl;
	}

}