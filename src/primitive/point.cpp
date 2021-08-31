#include "../../include/primitive/point.hpp"
#include <cassert>

namespace pots {

template<typename T>
point<T>::point(const T& x, const T& y, const T& z)
	: x_(x), y_(y), z_(z) 
{
}
template point<double>::point(const double&, const double&, const double&);
template point<float>::point(const float&, const float&, const float&);

template<typename T>
point<T>::point(const std::initializer_list<T>& init) {
	assert(init.size() == 3);

	this->x_ = *init.begin();
	this->y_ = *(init.begin() + 1);
	this->z_ = *(init.begin() + 2);
}
template point<double>::point(const std::initializer_list<double>&);
template point<float>::point(const std::initializer_list<float>&);

}
