#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

class grid;

class edge {
private:
	std::vector<id_type> node_ids_;
	
	const grid& rgrid_;
protected:
public:
	edge(const std::vector<id_type>&, const grid&);	
	edge(const std::initializer_list<id_type>&, const grid&);	

	std::vector<id_type> nids() const;
};

}
