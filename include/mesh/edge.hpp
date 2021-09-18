#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

template<class grid_t>
class edge {
public:

private:
protected:
	std::vector<id_type> node_ids_;

	const grid_t& ref_;
	
public:
	edge(const std::vector<id_type>&, const grid_t&);	

	const std::vector<id_type>& nids() const;
};

}

#include "impl/edge_impl.hpp"
