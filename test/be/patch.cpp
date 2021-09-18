#include "../../include/be/patch.hpp"
#include "../../include/mesh/grid.hpp"
#include "../../include/mesh/edge.hpp"
#include "../../include/geometry/segment.hpp"
#include "../../include/mesh/linear_discretizer.hpp"
#include "../test_util.hpp"
#include "gtest/gtest.h"

class mock_element: public pots::be::element {
private: 
	pots::be::scalar_d intensity_ = 5;
public:
	pots::be::scalar_d intensity() const override { return this->intensity_; }
	void set_intensity(pots::be::scalar_d m) override { this->intensity_ = m; }
	pots::be::vector_d influence(const pots::point_d& p) const override { return { 1, 2, 3 }; }
	pots::be::vector_d dq(const pots::point_d& p) const override { return { 2, 3, 4 }; }
};

class mock_grid: public pots::mesh::grid<mock_grid, pots::mesh::edge<mock_grid>, pots::be::patch<mock_grid>> {
public:
	using grid<mock_grid, pots::mesh::edge<mock_grid>, pots::be::patch<mock_grid>>::grid;
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


TEST(PatchTet, PatchCountTest) {
	t_eq_assert(patches.size(), 1);
}

TEST(PatchTest, NIDsTest) {
	t_eq_assert(patches[0].nids().size(), 4);
}

TEST(PatchTest, NodeTest) {
	t_eq_assert(grid.nodes()[patches[0].nids()[0]].p(), {0.0, 0.0, 0.0});
	t_eq_assert(grid.nodes()[patches[0].nids()[1]].p(), {10.0, 0.0, 0.0});
	t_eq_assert(grid.nodes()[patches[0].nids()[2]].p(), {10.0, 3.0, 0.0});
	t_eq_assert(grid.nodes()[patches[0].nids()[3]].p(), {0.0, 3.0, 0.0});
}

TEST(PatchTest, CpTest) {
	t_eq_assert(patches[0].cp(), {5.0, 1.5, 0.0});
}

TEST(PatchTest, nTest) {
	t_eq_assert(patches[0].n()[0], 0.0);
	t_eq_assert(patches[0].n()[1], 0.0);
	t_eq_assert(patches[0].n()[2], 1.0);
}

