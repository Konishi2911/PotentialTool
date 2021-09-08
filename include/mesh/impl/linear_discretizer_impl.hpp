#pragma once 

namespace pots::mesh {

template<class grid_t>
linear_discretizer<grid_t>::linear_discretizer(const domain& dom, size_t M, size_t N):
	discretizer<grid_t>::discretizer(dom, M, N)
{}


template<class grid_t>
std::vector<node> linear_discretizer<grid_t>::nodes_() const {
	auto nodes = std::vector<node>();
	auto curve = this->dom_.edge(0);
	for (auto v: this->v_dist_()) {
		for (auto u: this->u_dist_()) {
			nodes.push_back(this->dom_.p(u, v));
		}
	}
	return nodes;
}


template<class grid_t>
std::vector<typename grid_t::edge_type::source> linear_discretizer<grid_t>::edges_() const {
	auto edges = std::vector<typename grid_t::edge_type::source>();
	for (auto i = 0U; i <= this->N_; ++i) {
		for (auto j = 0U; j < this->M_; ++j) {
			edges.emplace_back(
				typename grid_t::edge_type::source {
					static_cast<id_type>(i * (this->M_ + 1) + j),
					static_cast<id_type>(i * (this->M_ + 1) + j + 1)
				}
			);
		}
	}
	for (auto i = 0U; i < this->N_; ++i) {
		for (auto j = 0U; j <= this->M_; ++j) {
			edges.emplace_back(
				typename grid_t::edge_type::source {
					static_cast<id_type>(i * (this->M_ + 1) + j),
					static_cast<id_type>((i + 1) * (this->M_ + 1) + j)
				}
			);
		}
	}
	return edges;
}

template<class grid_t>
std::vector<typename grid_t::face_type::source> linear_discretizer<grid_t>::faces_() const {
	auto faces = std::vector<typename grid_t::face_type::source>();
	for (auto i = 0U; i < this->N_; ++i) {
		auto offset = (this->N_ + 1) * this->M_ + i;
		for (auto j = 0U; j < this->M_; ++j) {
			faces.emplace_back(
				typename grid_t::face_type::source {
					static_cast<id_type>(i * this->M_ + j),
					static_cast<id_type>(i * this->M_ + j + offset + 1),
					static_cast<id_type>((i + 1) * this->M_ + j),
					static_cast<id_type>(i * this->M_ + j + offset)
				}
			);
		}
	}
	return faces;
}


template<class grid_t>
std::vector<double> linear_discretizer<grid_t>::u_dist_() const {
	auto dist = std::vector<double>();
	for (auto i = 0; i <= this->M_; ++i) {
		dist.emplace_back(static_cast<double>(i) / this->M_);
	}
	return dist;
}

template<class grid_t>
std::vector<double> linear_discretizer<grid_t>::v_dist_() const {
	auto dist = std::vector<double>();
	for (auto i = 0; i <= this->N_; ++i) {
		dist.emplace_back(static_cast<double>(i) / this->N_);
	}
	return dist;
}

}
