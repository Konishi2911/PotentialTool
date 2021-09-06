#pragma once

#include <limits>
#include <initializer_list>

namespace pots {

template<typename T> struct point {
private:
	T x_, y_, z_;

public:
	point(const T& x, const T& y, const T& z);
	point(const std::initializer_list<T>& init);

	const T& x() const { return this->x_; }
	const T& y() const { return this->y_; }
	const T& z() const { return this->z_; }
	T& x() { return this->x_; }
	T& y() { return this->y_; }
	T& z() { return this->z_; }
};


template<typename T> point<T> operator+(const point<T>&, const point<T>&);
template<typename T> point<T> operator-(const point<T>&, const point<T>&);
template<typename T> point<T> operator*(T, const point<T>&);
template<typename T> point<T> operator*(const point<T>&, T);

template<typename T> bool operator==(const point<T>&, const point<T>&);
template<typename T> bool operator!=(const point<T>&, const point<T>&);


using point_f = point<float>;
using point_d = point<double>;

}
