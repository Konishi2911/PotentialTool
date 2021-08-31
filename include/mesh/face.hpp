#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

class grid;

class face {
private:
	std::vector<id_type> edge_ids_;

	const grid& rgrid_;
protected:
public:
	face(const std::vector<id_type>& edges, const grid& ref);
	face(const std::initializer_list<id_type>& edges, const grid& ref);

	std::vector<id_type> eids() const;
};

}
