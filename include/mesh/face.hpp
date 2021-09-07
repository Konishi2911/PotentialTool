#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

template<class grid_t>
class face {
public:
	using source = std::vector<id_type>;

private:
	std::vector<id_type> edge_ids_;

	const grid_t& rgrid_;
protected:
public:
	face(const std::vector<id_type>& edges, const grid_t& ref);
	face(const std::initializer_list<id_type>& edges, const grid_t& ref);

	std::vector<id_type> eids() const;
};

}

#include "impl/face_impl.hpp"
