#pragma once 

namespace pots::mesh {

linear_discretizer::linear_discretizer(const domain& dom, size_t M, size_t N):
	discretizer::discretizer(dom, M, N)
{}


std::vector<node> linear_discretizer::nodes_() const {
	auto nodes = std::vector<node>();
	auto curve = this->dom_.edge(0);
	for (auto v: this->v_dist_()) {
		for (auto u: this->u_dist_()) {
			nodes.push_back(this->dom_.p(u, v));
		}
	}
	return nodes;
}


std::vector<std::vector<id_type>> linear_discretizer::edge_sources_() const {
	auto edges = std::vector<std::vector<id_type>>();
	for (auto i = 0U; i <= this->N_; ++i) {
		for (auto j = 0U; j < this->M_; ++j) {
			edges.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (this->M_ + 1) + j),
					static_cast<id_type>(i * (this->M_ + 1) + j + 1)
				}
			);
		}
	}
	for (auto i = 0U; i < this->N_; ++i) {
		for (auto j = 0U; j <= this->M_; ++j) {
			edges.emplace_back(
				std::vector<id_type> {
					static_cast<id_type>(i * (this->M_ + 1) + j),
					static_cast<id_type>((i + 1) * (this->M_ + 1) + j)
				}
			);
		}
	}
	return edges;
}

std::vector<std::vector<id_type>> linear_discretizer::face_sources_() const {
	auto faces = std::vector<std::vector<id_type>>();
	for (auto i = 0U; i < this->N_; ++i) {
		auto offset = (this->N_ + 1) * this->M_ + i;
		for (auto j = 0U; j < this->M_; ++j) {
			faces.emplace_back(
				std::vector<id_type> {
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


std::vector<double> linear_discretizer::u_dist_() const {
	auto dist = std::vector<double>();
	for (auto i = 0; i <= this->M_; ++i) {
		dist.emplace_back(static_cast<double>(i) / this->M_);
	}
	return dist;
}

std::vector<double> linear_discretizer::v_dist_() const {
	auto dist = std::vector<double>();
	for (auto i = 0; i <= this->N_; ++i) {
		dist.emplace_back(static_cast<double>(i) / this->N_);
	}
	return dist;
}

}
