/**
* @file vortex_ring.hpp
* @auther K.Konishi
* @date Sep.2, 2021
*/

#pragma once 

#include "element.hpp"
#include "vortex_segment.hpp"
#include "type_alias.hpp"
#include <Eigen/Dense>
#include <array>

namespace pots::be {

class vortex_ring: element {
private:
	std::array<vortex_segment, 4> v_seg_;

protected:
public:
	/**
	* Constructs vortex ring whose circulation is gamma.
	* Note that p1 to p4 should be specified counterclockwise from top of the vortex ring.
	* @param gamma Circulation of this vortex ring.
	*/
	vortex_ring(scalar_d gamma, const point_d& p1, const point_d& p2, const point_d& p3, const point_d& p4);

	vector_d influence(const point_d&) const override;
	vector_d dq(const point_d&) const override;
};

}
