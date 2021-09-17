#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

class edge {
public:

private:
protected:
	std::vector<id_type> node_ids_;
	
public:
	edge(const std::vector<id_type>&);	
	edge(const std::initializer_list<id_type>&);	

	const std::vector<id_type>& nids() const;
};

}

#include "impl/edge_impl.hpp"
