#include "../../include/geometry/polyline.hpp"
#include "../../include/geometry/segment.hpp"

namespace pots::geometry {

polyline::polyline(const std::vector<point_d>& pset): 
	p_set_(pset) 
{
	this->l_ = 0;
	for (auto i = 0; i < pset.size() - 1; ++i) {
		this->l_ += segment(pset[i], pset[i + 1]).length();
	}
}

polyline::polyline(const std::initializer_list<point_d>& init): 
	p_set_(init.begin(), init.end()) 
{
	this->l_ = 0;
	for (auto i = 0; i < this->p_set_.size() - 1; ++i) {
		this->l_ += segment(this->p_set_[i], this->p_set_[i + 1]).length();
	}
}


const point_d& polyline::sp() const { return this->p_set_[0]; }
const point_d& polyline::ep() const { return this->p_set_[this->p_set_.size() - 1]; }

double polyline::length() const { return this->l_; }

point_d polyline::p(double u) const {
	double l_ratio_acc = 0.0;
	for (auto i = 0; i < this->p_set_.size() - 1; ++i) {
		auto seg = segment(this->p_set_[i], this->p_set_[i + 1]);
		auto l_ratio = seg.length() / this->length();

		if ((l_ratio_acc + l_ratio) < u) { 
			l_ratio_acc += l_ratio;
			continue; 
		}
		return seg.p((u - l_ratio_acc) / l_ratio);
	}
	return this->ep();
}


}
