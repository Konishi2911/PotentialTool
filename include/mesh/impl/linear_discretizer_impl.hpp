#pragma once 
#include "../linear_descritizer.hpp"

namespace pots::mesh {

template<class edge_t, class face_t>
linear_discretizer<edge_t, face_t>::linear_discretizer(const domain&, dom, size_t N, size_t M):
	dom_(dom), N_(N), M_(M)
{}


template<class edge_t, class face_t>
std::vector<node> linear_discretizer<edge_t, face_t>::nodes() const {
	auto nodes = std::vector<node>();
	auto curve = this->dom_.edge(0);
	for (auto v: this->v_dist_()) {
		for (auto u: this->u_dist_()) {
			nodes.push_back(this->dom_.p(u, v));
		}
	}
}

template<class edge_t, class face_t>
std::vector<edge_t> linear_discretizer<edge_t, face_t>::edges() const {
	auto edges = std::vector<edge_t>();
	for (auto i = 0U; i <= N; ++i) {
		for (auto j = 0U; j < M; ++j) {
			edges.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (this->M + 1) + j),
					static_cast<id_tyoe>(i * (this->M + 1) + j + 1)
				}
				*this
			);
		}
	}
	for (auto i = 0U; i < N; ++i) {
		for (auto j = 0U; j <= M; ++j) {
			edges.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (this->M + 1) + j),
					static_cast<id_tyoe>((i + 1) * (this->M + 1) + j)
				}
				*this
			);
		}
	}
	return edges;
}

template<class edge_t, class face_t>
std::vector<face_t> linear_discretizer<edge_t, face_t>::faces() const {
	auto faces = std::vector<face_t>();
	for (auto i = 0U; i < N; ++i) {
		auto offset = (N + 1) * M + i;
		for (auto j = 0U; j < M; ++j) {
			faces.emplace_back(
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
	return faces;
}



}
