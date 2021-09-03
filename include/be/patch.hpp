#pragma once 

#include "../mesh/face.hpp"

namespace pots::be {

class patch: mesh::face {
private:
protected:
public:
	/**
	* Returns position of the control point of this element.
	* @return Position of the control point.
	*/
	point_d cnt_point() const;

	/**
	* Returns the singularity element specified on this patch.
	* @return The singulatity element.
	*/
	element& get_element() const;
};

}
