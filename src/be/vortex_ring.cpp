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

auto vortex_ring::dq(const point_d& p) const -> vector_d {
	auto iv = vector_d();
	for (auto seg: this->v_seg_) {
		iv += seg.dq(p);
	}
	return iv;
}

}
