/**
* @file linear_discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once
#include "../primitive/point.hpp"

namespace pots::geometry {

class curve {
private:
protected:
public:
	/**
	* Returns start point
	* @return Start point
	*/
	virtual const point_d& sp() const = 0;

	/**
	* Returns end point
	* @return end point
	*/
	virtual const point_d& ep() const = 0;


	/**
	* Returns a point specified by given u [0, 1] on local corrdinate.
	* @param u A variable that range is closed interval [0, 1].
	* @return The point.
	*/
	virtual point_d p(double u) const = 0;

	/**
	* Calculates and returns the total length of itself.
	* @return the length of itself
	*/
	virtual double length() const = 0;
};

}
