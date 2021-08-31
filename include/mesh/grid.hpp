#pragma once

#include "../primitive/types.hpp"
#include "./node.hpp"
#include "./edge.hpp"
#include "./face.hpp"

namespace pots::mesh {

class grid {
private:
	std::vector<node> nodes_;
	std::vector<edge> edges_;
	std::vector<face> faces_;


	// For debugging
	grid(const point_d& ps, double width, double height, int N, int M);

protected:
public:
	const std::vector<face>& faces() const;	
	const std::vector<edge>& edges() const;	
	const std::vector<node>& nodes() const;	
	
	static grid test_case1();
};
	
}
