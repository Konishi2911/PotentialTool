/**
* @file element.hpp
* @auther K.Konishi
* @date Sep.2, 2021
*/

#pragma once

#include "../primitive/point.hpp"
#include "type_alias.hpp"

namespace pots::be {

class element {
private:
protected:
public:
	/**
	* Calculates and Returns the velocity induced by this element at given point.
	* @param p A point to calculate the induced velocity.
	* @return vector_d Induced velocity.
	*/
	virtual vector_d dq(const point_d&) const = 0;
};

}
