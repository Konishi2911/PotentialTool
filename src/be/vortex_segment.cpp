#include "../../include/be/vortex_segment.hpp"

namespace pots::be {

vortex_segment::vortex_segment(scalar_d gamma, const point_d& start, const point_d& end):
	gamma_(gamma),
	ps_(start),
	pe_(end),
	r0_(
		start.x() - end.x(),
		start.y() - end.y(),
		start.z() - end.z()
	)
{
}

auto vortex_segment::influence(const point_d& p) const -> vector_d {
	vector_d r1 = vector_d(
		p.x() - this->ps_.x(),
		p.y() - this->ps_.y(),
		p.z() - this->ps_.z()
	);
	vector_d r2 = vector_d(
		p.x() - this->pe_.x(),
		p.y() - this->pe_.y(),
		p.z() - this->pe_.z()
	);

	auto k = this->k_pi;
	auto tmp1 = this->r0_.dot(r1 / r1.norm() - r2 / r2.norm());
	auto tmp_vec = this->r0_.cross(r1);

	return k * tmp1 * tmp_vec / tmp_vec.norm();
}

auto vortex_segment::dq(const point_d& p) const -> vector_d {
	return this->influence(p) * this->gamma_;
}

}
