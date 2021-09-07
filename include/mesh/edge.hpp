#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

template<class grid_t>
class edge {
public:
	using source = std::vector<id_type>;

private:
	std::vector<id_type> node_ids_;
	
	const grid_t& rgrid_;
protected:
public:
	edge(const std::vector<id_type>&, const grid_t&);	
	edge(const std::initializer_list<id_type>&, const grid_t&);	

	std::vector<id_type> nids() const;
};

}

#include "impl/edge_impl.hpp"
