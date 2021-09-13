#include "../../include/mesh/linear_discretizer.hpp"
#include "../../include/mesh/grid.hpp"
#include "../../include/mesh/edge.hpp"
#include "../../include/mesh/face.hpp"
#include "../test_util.hpp"
#include "gtest/gtest.h"

class mock_grid;

class mock_grid: public pots::mesh::grid<mock_grid, pots::mesh::edge<mock_grid>, pots::mesh::face<mock_grid>> {
public:
	using grid<mock_grid, pots::mesh::edge<mock_grid>, pots::mesh::face<mock_grid>>::grid;
};


auto dom = pots::mesh::domain(
	{
		std::make_shared<pots::geometry::segment>(pots::point_d{0, 0, 0}, pots::point_d{10, 0, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{10, 0, 0}, pots::point_d{10, 3, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{10, 3, 0}, pots::point_d{0, 3, 0}),
		std::make_shared<pots::geometry::segment>(pots::point_d{0, 3, 0}, pots::point_d{0, 0, 0})
	}
);
auto discretizer = pots::mesh::linear_discretizer<mock_grid>{dom, 5, 4};
auto grid = discretizer.create_grid();


TEST(DiscretizerTest, NodeTest) {
	auto nodes = grid.nodes();
	t_eq_assert(nodes.size(), 30);
}

TEST(DiscretizerTest, EdgeTest) {
	auto edges = grid.edges();
	t_eq_assert(edges.size(), 49);
}

TEST(DiscretizerTest, FaceTest) {
	auto faces = grid.faces();
	t_eq_assert(faces.size(), 20);
}

TEST(DiscretizerTest, EdgeAddressingTest) {
	auto edges = grid.edges();
	t_eq_assert(edges[0].nids()[0], 0);
	t_eq_assert(edges[0].nids()[1], 1);
	t_eq_assert(edges[24].nids()[0], 28);
	t_eq_assert(edges[24].nids()[1], 29);
	t_eq_assert(edges[32].nids()[0], 7);
	t_eq_assert(edges[32].nids()[1], 13);
	t_eq_assert(edges[48].nids()[0], 23);
	t_eq_assert(edges[48].nids()[1], 29);
}

TEST(DiscretizerTest, FaceAddressingTest) {
	auto faces = grid.faces();
	t_eq_assert(faces[0].eids()[0], 0);
	t_eq_assert(faces[0].eids()[1], 26);
	t_eq_assert(faces[0].eids()[2], 5);
	t_eq_assert(faces[0].eids()[3], 25);

	t_eq_assert(faces[19].eids()[0], 19);
	t_eq_assert(faces[19].eids()[1], 48);
	t_eq_assert(faces[19].eids()[2], 24);
	t_eq_assert(faces[19].eids()[3], 47);
}
