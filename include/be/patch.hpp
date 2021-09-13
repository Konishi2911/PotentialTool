/**
* @file patch.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once 

#include "../mesh/face.hpp"
#include "type_alias.hpp"
#include "element.hpp"
#include <memory>

namespace pots::be {

template<class grid_t>
class patch: public mesh::face<grid_t> {
private:

	void init();

protected:
public:
	patch(const std::vector<id_type>& edges, const grid_t& ref);

	/**
	* Returns the node points that consist this patch
	* @return The list of the points.
	*/
	std::vector<point_d> np() const;

	/**
	* Calculate and Returns the normal vector of this patch.
	* @return The normal vector
	*/
	vector_d n() const;

	/** 
	* Calculate and Returns the control point of this patch 
	* @return The control point
	*/
	point_d cp() const;

};

}

#include "impl/patch_impl.hpp"
