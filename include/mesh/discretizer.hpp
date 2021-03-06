/**
* @file discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once
#include "domain.hpp"
#include "node.hpp"
#include "../primitive/types.hpp"
#include <vector>

namespace pots::mesh {

class discretizer {
private:
protected:
	size_t N_, M_;	
	domain dom_;

	/**
	* Returns an array of nodes.
	* @return An array of nodes.
	*/
	virtual std::vector<node> nodes_() const = 0;

	/**
	* Returns an array of edges.
	* @return An array of edges.
	*/
	virtual std::vector<std::vector<id_type>> edge_sources_() const = 0;

	/**
	* Returns an array of faces.
	* @return An array of faces.
	*/
	virtual std::vector<std::vector<id_type>> face_sources_() const = 0;


public:
	discretizer(const domain& dom, size_t M, size_t N): dom_(dom), N_(N), M_(M) {}

	/**
	* Get number of division directed to y axis.
	* @return Number of divisions directs for y axis.
	*/
	size_t N() const { return N_; }

	/**
	* Get number of division directed to x axis.
	* @return Number of divisions directs for x axis.
	*/
	size_t M() const { return M_; }


	/**
	* Create grid object.
	* @return grid object
	*/
	template<class grid_t>
	grid_t create_grid() const;
};

}

#include "impl/discretizer_impl.hpp"
