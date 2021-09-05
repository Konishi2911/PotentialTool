#include "../../include/geometry/segment.hpp"
#include <cmath>

namespace pots::geometry {

segment::segment(const point_d& sp, const point_d& ep):
	sp_(sp), ep_(ep) 
{
}

point_d segment::p(double u) const {
	return {
		this->sp_.x() + (this->ep_.x() - this->sp_.x()) * u,
		this->sp_.y() + (this->ep_.y() - this->sp_.y()) * u,
		this->sp_.z() + (this->ep_.z() - this->sp_.z()) * u
	};
}

double segment::length() const {
	return std::sqrt( 
		std::pow(this->ep_.x() - this->sp_.x(), 2) + 
		std::pow(this->ep_.y() - this->sp_.y(), 2)
	);
}

}
