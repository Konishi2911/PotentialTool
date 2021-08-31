#include "../../include/mesh/face.hpp"
#include "../../include/mesh/grid.hpp"

namespace pots::mesh {

face::face(const std::vector<id_type>& edges, const grid& grid)
	: edge_ids_(edges), rgrid_(grid) 
{
}

face::face(const std::initializer_list<id_type>& init, const grid& grid)
	: edge_ids_(init.begin(), init.end()), rgrid_(grid) 
{
}


std::vector<id_type> face::eids() const {
	return this->edge_ids_;
}
	
}
