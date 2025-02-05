#pragma once
#include <vector>

namespace cy {
	template <typename T>
	class Vector {
	public:
		Vector() {}
		Vector(const size_t& dimension, const T& value) :mDimension(dimension), mData(dimension, value) {}
		Vector(T* data, size_t dimension) : mDimension(dimension), mData(data, data + dimension) {}
		Vector(std::vector<T>& other) : mDimension(other.size()), mData(other) {}
		Vector(Vector<T>& other) : mDimension(other.mDimension), mData(other.mData) {}
		~Vector() {}

		//스칼라연산
		friend Vector<T> operator+(const Vector<T>& vec, const T& scalar);
		friend Vector<T> operator+(const T& scalar, const Vector<T>& vec);

		friend Vector<T> operator-(const Vector<T>& vec, const T& scalar);
		friend Vector<T> operator-(const T& scalar, const Vector<T>& vec);

		friend Vector<T> operator*(const Vector<T>& vec, const T& scalar);
		friend Vector<T> operator*(const T& scalar, const Vector<T>& vec);

		//friend Vector<T> operator/(const Vector<T>& vec, const T& scalar);
		//friend Vector<T> operator/(const T& scalar, const Vector<T>& vec);

		Vector<T>& operator+=(const T& scalar);
		Vector<T>& operator-=(const T& scalar);
		Vector<T>& operator*=(const T& scalar);
		//Vector<T>& operator/=(const T& scalar);

		//벡터연산
		//Vector<T> cross(const Vector<T>& other);
		T dot(const Vector<T>& a, const Vector<T>& b);

		bool operator==(const Vector<T>& other);
		bool operator!=(const Vector<T>& other);
		bool operator>(const Vector<T>& other);
		bool operator<(const Vector<T>& other);
		bool operator>=(const Vector<T>& other);
		bool operator<=(const Vector<T>& other);

		//기타연산
		T norm();
		friend T getDist(const Vector<T>& other);

	private:
		size_t mDimension;
		std::vector<T> mData;
	};
}

#include "type.hpp"