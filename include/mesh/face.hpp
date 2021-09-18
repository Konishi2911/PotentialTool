#pragma once

#include "../primitive/types.hpp"
#include <vector>
#include <initializer_list>

namespace pots::mesh {

template<class grid_t>
class face {
public:

private:
protected:
	std::vector<id_type> node_ids_;
	std::vector<id_type> edge_ids_;

	const grid_t& ref_;

	static std::vector<id_type> calc_nids_(const std::vector<id_type>&, const grid_t&);
public:
	face(const std::vector<id_type>& eids, const grid_t& nids);

	const std::vector<id_type>& nids() const;
	const std::vector<id_type>& eids() const;
};

}

#include "impl/face_impl.hpp"
