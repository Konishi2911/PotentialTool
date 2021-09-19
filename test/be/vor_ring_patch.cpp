#include "../../include/be/vor_ring_patch.hpp"
#include "../../include/be/vortex_ring.hpp"
#include "../../include/mesh/grid.hpp"
#include "../../include/mesh/edge.hpp"
#include "../../include/mesh/linear_discretizer.hpp"
#include "../../include/mesh/domain.hpp"
#include "../../include/geometry/segment.hpp"

#include "../test_util.hpp"
#include "gtest/gtest.h"

class mock_grid: public pots::mesh::grid<mock_grid, pots::mesh::edge<mock_grid>, pots::be::vor_ring_patch<mock_grid>> {
public:
	using grid<mock_grid, pots::mesh::edge<mock_grid>, pots::be::vor_ring_patch<mock_grid>>::grid;
};

auto dom = pots::mesh::domain(
	{
		std::make_shared<pots::geometry::segment>(pots::point_d{0, 0, 0}, pots::point_d{10, 0, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{10, 0, 0}, pots::point_d{10, 3, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{10, 3, 0}, pots::point_d{0, 3, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{0, 3, 0}, pots::point_d{0, 0, 0})
	}
);
auto discretizer = pots::mesh::linear_discretizer{dom, 1, 1};
auto grid = discretizer.create_grid<mock_grid>();

auto patches = grid.faces();

TEST(VorRingPatchTest, InfluenceTest) {
	auto elem = pots::be::vortex_ring(
		10, 
		{0, 0, 0}, {10, 0, 0}, {10, 3, 0}, {0, 3, 0}
	);
	
	auto patch = patches[0];
	auto prove = pots::point_d{-10, -2, -4};
	auto flu = patch.influence(prove);
	auto exact_flu = elem.influence(prove);
	t_eq_assert(flu[0], exact_flu[0]);
	t_eq_assert(flu[1], exact_flu[1]);
	t_eq_assert(flu[2], exact_flu[2]);
}

TEST(VorRingPatchTest, dQTest) {
	auto elem = pots::be::vortex_ring(
		10,
		{0, 0, 0}, {10, 0, 0}, {10, 3, 0}, {0, 3, 0}
	);
	
	auto patch = patches[0];
	patch.set_intensity(10.0);

	auto prove = pots::point_d{-10, -2, -4};
	auto dq = patch.dq(prove);
	auto exact_dq = elem.dq(prove);
	t_eq_assert(dq[0], exact_dq[0]);
	t_eq_assert(dq[1], exact_dq[1]);
	t_eq_assert(dq[2], exact_dq[2]);
}

