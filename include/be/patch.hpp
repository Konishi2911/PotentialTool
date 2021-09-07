/**
* @file patch.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#pragma once 

#include "../mesh/face.hpp"
#include "../primitive/types.hpp"
#include "element.hpp"
#include <memory>

namespace pots::be {

template<class grid_t>
class patch: public mesh::face<grid_t> {
private:
	std::unique_ptr<element> element_;

	void init();

protected:
public:
	patch(const std::vector<id_type>& edges, const grid_t& ref);

	/**
	* Returns the singularity element specified on this patch.
	* @return The singulatity element.
	*/
	element& get_element() const;
};

}
