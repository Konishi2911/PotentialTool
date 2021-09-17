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

/**
* @brief Represents a patch face that consists of four edges.
*/
class patch: public mesh::face {
private:

	void init();

protected:
public:
	template<class grid_t>
	patch(const std::vector<id_type>& eids, const grid_t& ref);

	/**
	* Returns the node points that consist this patch
	* @return The list of the points.
	*/
	template<class grid_t>
	std::vector<point_d> np(const grid_t&) const;

	/**
	* Calculate and Returns the normal vector of this patch.
	* @return The normal vector
	*/
	template<class grid_t>
	vector_d n(const grid_t&) const;

	/** 
	* Calculate and Returns the control point of this patch 
	* @return The control point
	*/
	template<class grid_t>
	point_d cp(const grid_t&) const;

};

}

#include "impl/patch_impl.hpp"
