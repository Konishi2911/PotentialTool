#include "../../include/be/vortex_ring.hpp"

namespace pots::be {

vortex_ring::vortex_ring(scalar_d gamma, const point_d& p1, const point_d& p2, const point_d& p3, const point_d& p4):
	v_seg_({
		vortex_segment(gamma, p1, p2),
		vortex_segment(gamma, p2, p3),
		vortex_segment(gamma, p3, p4),
		vortex_segment(gamma, p4, p1)
	})
{
}

vortex_ring::vortex_ring(scalar_d gamma, const std::vector<point_d>& vp):
	v_seg_({
		vortex_segment(gamma, vp[0], vp[1]),
		vortex_segment(gamma, vp[1], vp[2]),
		vortex_segment(gamma, vp[2], vp[3]),
		vortex_segment(gamma, vp[3], vp[4])
	})
{
}


auto vortex_ring::intensity() const -> scalar_d {
	return this->v_seg_[0].intensity();
}
auto vortex_ring::set_intensity(scalar_d m) -> void {
	for (auto v_seg: this->v_seg_) {
		v_seg.set_intensity(m);
	}
}

auto vortex_ring::influence(const point_d& p) const -> vector_d {
	auto iv = vector_d();
	for (auto seg: this->v_seg_) {
		iv += seg.influence(p);
	}
	return iv;
}

auto vortex_ring::dq(const point_d& p) const -> vector_d {
	auto iv = vector_d();
	for (auto seg: this->v_seg_) {
		iv += seg.dq(p);
	}
	return iv;
}


}
