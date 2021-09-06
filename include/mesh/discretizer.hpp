/**
* @file discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once
#include "domain.hpp"
#include <vector>

namespace pots::mesh {

template<class edge_t, class face_t>
class discretizer {
private:
protected:
	size_t N_, M_;	
	domain dom_;

public:
	discretizer(const domain&, size_t N, size_t M);


	/**
	* Get number of division directed to y axis.
	* @return Number of divisions directs for y axis.
	*/
	size_t N() const { return N_; }

	/**
	* Get and set number of division directed to y axis.
	* @return Reference to number of divisions directs for y axis.
	*/
	size_t& N() { return N_; }

	/**
	* Get number of division directed to x axis.
	* @return Number of divisions directs for x axis.
	*/
	size_t M() const { return M_; }

	/**
	* Get and set number of division directed to x axis.
	* @return Reference to number of divisions directs for x axis.
	*/
	size_t& M() { return M_; }


	/**
	* Returns an array of nodes.
	* @return An array of nodes.
	*/
	virtual std::vector<node> nodes() const = 0;

	/**
	* Returns an array of edges.
	* @return An array of edges.
	*/
	virtual std::vector<edge_t> edges() const = 0;

	/**
	* Returns an array of faces.
	* @return An array of faces.
	*/
	virtual std::vector<face_t> faces() const = 0;
};

}
