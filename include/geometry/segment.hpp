/**
* @file linear_discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once
#include "curve.hpp"

namespace pots::geometry {

class segment: curve {
private:
	point_d sp_;
	point_d ep_;

protected:
public:
	segment(const point_d& sp, const point_d& ep);

	const point_d& sp() const override { return this->sp_; }
	const point_d& ep() const override { return this->ep_; }

	point_d p(double u) const override;
	double length() const override;
};

}
