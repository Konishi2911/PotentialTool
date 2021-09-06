#include "../../include/primitive/point.hpp"
#include <cmath>
#include <cassert>

namespace pots {

template<typename T>
point<T>::point(const T& x, const T& y, const T& z)
	: x_(x), y_(y), z_(z) 
{
}

template<typename T>
point<T>::point(const std::initializer_list<T>& init) {
	assert(init.size() == 3);

	this->x_ = *init.begin();
	this->y_ = *(init.begin() + 1);
	this->z_ = *(init.begin() + 2);
}


template<typename T>
point<T> operator+(const point<T>& p1, const point<T>& p2) {
	return {
		p1.x() + p2.x(),
		p1.y() + p2.y(),
		p1.z() + p2.z(),
	};
}
template point<float> operator+(const point<float>&, const point<float>&);
template point<double> operator+(const point<double>&, const point<double>&);

template<typename T>
point<T> operator-(const point<T>& p1, const point<T>& p2) {
	return {
		p1.x() - p2.x(),
		p1.y() - p2.y(),
		p1.z() - p2.z(),
	};
}
template point<float> operator-(const point<float>&, const point<float>&);
template point<double> operator-(const point<double>&, const point<double>&);

template<typename T>
point<T> operator*(T a, const point<T>& p) {
	return {
		a * p.x(),
		a * p.y(),
		a * p.z(),
	};
}
template point<float> operator*(float, const point<float>&);
template point<double> operator*(double, const point<double>&);

template<typename T>
point<T> operator*(const point<T>& p, T a) {
	return a * p;
}
template point<float> operator*(const point<float>&, float);
template point<double> operator*(const point<double>&, double);

template<typename T>
bool operator==(const point<T>& p1, const point<T>& p2) {
	return 
		std::abs(p1.x() - p2.x()) < std::numeric_limits<T>::epsilon() &&
		std::abs(p1.y() - p2.y()) < std::numeric_limits<T>::epsilon() &&
		std::abs(p1.z() - p2.z()) < std::numeric_limits<T>::epsilon();
}
template bool operator==(const point<float>&, const point<float>&);
template bool operator==(const point<double>&, const point<double>&);

template<typename T>
bool operator!=(const point<T>& p1, const point<T>& p2) {
	return !(p1 == p2);
}
template bool operator!=(const point<float>&, const point<float>&);
template bool operator!=(const point<double>&, const point<double>&);


template class point<float>;
template class point<double>;

}
