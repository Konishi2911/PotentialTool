/**
* @file vortex_ring.hpp
* @auther K.Konishi
* @date Sep.2, 2021
*/

#pragma once
#include "element.hpp"
#include "type_alias.hpp"
#include <Eigen/Dense>
#include <cmath>

namespace pots::be {

class vortex_segment final: element {
private:
	/**
	* @brief 1 / (4 * PI)
	*/
	constexpr static scalar_d k_pi = 1 / (4 * M_PI);

	scalar_d gamma_;	
	point_d ps_;
	point_d pe_;

	vector_d r0_;

protected:
public:
	/**
	* @param gamma Circulation of this const vortex segment.
	* @param start Start point of this vortex segment.
	* @param end End point of this vortex segment.
	*/
	vortex_segment(scalar_d gamma, const point_d& start, const point_d& end);

	/**
	* @sa element
	*/
	vector_d dq(const point_d&) const override;

};

}


