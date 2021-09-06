#include "../../include/mesh/domain.hpp"

namespace pots::mesh {

domain::domain(const std::vector<std::shared_ptr<geometry::curve>>& boundaries):
	verts_(), edges_(boundaries)
{
	this->init_();
}

domain::domain(std::initializer_list<std::shared_ptr<geometry::curve>>& init):
	verts_(), edges_(init.begin(), init.end())
{
	this->init_();
}


void domain::init_() {
	if (this->edges_[0]->sp() != this->edges_[this->edges_.size() - 1]->ep()) {
		throw std::invalid_argument("Given boundaries are not closed.");
	}
	this->verts_.push_back(this->edges_[0]->sp());

	for (auto i = 0; i < this->edges_.size() - 1; ++i) {
		if (this->edges_[i]->ep() != this->edges_[i + 1]->sp()) {
			throw std::invalid_argument("Given boundaries are not closed.");
		}
		this->verts_.push_back(this->edges_[i]->ep());
	}
}

std::weak_ptr<geometry::curve> domain::edge(size_t i) const {
	if (i > this->edges_.size() - 1) { throw std::out_of_range("index i is out of range."); }
	return { this->edges_[i] };
}

point_d domain::p(double u, double v) const {
	return this->p1_(u, v) + this->p2_(u, v) - this->p3_(u, v);
}

point_d domain::p1_(double u, double v) const {
	return (1 - v) * this->edges_[0]->p(u) + v * this->edges_[2]->p(1 - u);
}

point_d domain::p2_(double u, double v) const {
	return (1 - u) * this->edges_[3]->p(1 - v) + u * this->edges_[1]->p(v);
}

point_d domain::p3_(double u, double v) const {
	return 
		(1 - v) * ( (1 - u) * this->edges_[3]->p(1) + u * this->edges_[1]->p(0) ) + 
		v * ( (1 - u) * this->edges_[3]->p(0) + u * this->edges_[1]->p(1) );
}
}
