/**
* @file polyline.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once
#include "curve.hpp"
#include <vector>
#include <initializer_list>

namespace pots::geometry {

class polyline: curve {
private:
	double l_;
	std::vector<point_d> p_set_;

protected:
public:
	polyline(const std::vector<point_d>&);
	polyline(const std::initializer_list<point_d>&);

	/**
	* Returns a number of control points.
	* @return the number of points
	*/
	size_t npoints() const;

	const point_d& sp() const override;
	const point_d& ep() const override;

	point_d p(double u) const override;
	double length() const override;
};

}
