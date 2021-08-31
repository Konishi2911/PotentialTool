#include "../../include/mesh/grid.hpp"

namespace pots::mesh {

grid::grid(const point_d& ps, double width, double height, int N, int M) {
	// - Generate nodes
	for (auto i = 0; i <= N; ++i) {
		auto offset_y = width * i / (double)N;
		for (auto j = 0; j <= M; ++j) {
			auto offset_x = height * j / (double)M;
			this->nodes_.emplace_back( point_d{ps.x() + offset_x, ps.y() + offset_y, ps.z()} );
		}
	}

	// - Generate edges
	for (auto i = 0; i <= N; ++i) {
		for (auto j = 0; j < M; ++j) {
			this->edges_.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (M + 1) + j), 
					static_cast<id_type>(i * (M + 1) + j + 1)
				}, 
				*this
			);
		}
	}
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j <= M; ++j) {
			this->edges_.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (M + 1) + j), 
					static_cast<id_type>((i + 1) * (M + 1) + j)
				}, 
				*this
			);
		}
	}

	// - Generate faces
	for (auto i = 0U; i < N; ++i) {
		auto offset = (N + 1) * M + i;
		for (auto j = 0U; j < M; ++j) { 
			this->faces_.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * M + j), 
					static_cast<id_type>((i + 1) * M + j), 
					static_cast<id_type>(i * M + j + offset), 
					static_cast<id_type>(i * M + j + offset + 1)
				}, 
				*this
			);
		}
	}
}


const std::vector<face>& grid::faces() const {
	return this->faces_;
}

const std::vector<edge>& grid::edges() const {
	return this->edges_;
}

const std::vector<node>& grid::nodes() const {
	return this->nodes_;
}

grid grid::test_case1() {
	return grid({0,0,0}, 10.0, 3.0, 5, 4);
}

}
