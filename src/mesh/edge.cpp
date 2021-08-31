#include "../../include/mesh/edge.hpp"
#include "../../include/mesh/grid.hpp"

namespace pots::mesh {

edge::edge(const std::vector<id_type>& nodes, const grid& grid)
	: node_ids_(nodes), rgrid_(grid) 
{
}

edge::edge(const std::initializer_list<id_type>& init, const grid& grid)
	: node_ids_(init.begin(), init.end()), rgrid_(grid) 
{
}

std::vector<id_type> edge::nids() const {
	return this->node_ids_;
}

}
