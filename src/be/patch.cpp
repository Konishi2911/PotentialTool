#include "../../include/be/patch.hpp"

namespace pots::be {

template<class grid_t>
patch<grid_t>::patch(const std::vector<id_type>& edges, const grid_t& ref):
	mesh::face<grid_t>::face(edges, ref) 
{ }


template<class grid_t>
element& patch<grid_t>::get_element() const {
	return *this->element_;
}

}
