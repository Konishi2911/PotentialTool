#pragma once

#include "../primitive/types.hpp"
#include "./node.hpp"
#include "./edge.hpp"
#include "./face.hpp"
#include "./discretizer.hpp"
#include <memory>

namespace pots::mesh {

template<class grid_t, class edge_t, class face_t>
class grid {
private:
	std::vector<face_t> faces_;
	std::vector<edge_t> edges_;
	std::vector<node> nodes_;

protected:
public:
	using edge_type = edge_t;
	using face_type = face_t;

	grid(const std::vector<node>&, const std::vector<typename edge_t::source>&, const std::vector<typename face_t::source>&);

	virtual const std::vector<face_t>& faces() const;
	virtual const std::vector<edge_t>& edges() const;	
	virtual const std::vector<node>& nodes() const;	
};
	
}

#include "impl/grid_impl.hpp"
