#include "../../include/be/vortex_segment.hpp"
#include "../test_util.hpp"
#include "gtest/gtest.h"


auto gamma = 1.0;
auto p1 = pots::point_d { 0.0, 0.0, 0.0 };
auto p2 = pots::point_d { 0.0, 1.0, 0.0 };

auto v_seg = pots::be::vortex_segment(gamma, p1, p2);


TEST(VortexSegmentTest, InfluenceTest) {
	auto p_probe = pots::point_d { 1.0, 0.5, 0 };
	auto dq = v_seg.dq(p_probe);
	t_eq_assert(dq.norm(), 0.07117625434);
}

TEST(VortexSegmentTest, IntensityTest) {
	auto intensity = 10.0;
	v_seg.set_intensity(intensity);
	t_eq_assert(v_seg.intensity(), intensity);
}

