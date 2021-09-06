#include "../../include/mesh/domain.hpp"
#include "../../include/geometry/segment.hpp"
#include "../test_util.hpp"

int main() {
	auto dom = pots::mesh::domain(
		{
			std::make_shared<pots::geometry::segment>(pots::point_d{0, 0, 0}, pots::point_d{0, 3, 0}),
			std::make_shared<pots::geometry::segment>(pots::point_d{0, 3, 0}, pots::point_d{10, 3, 0}),
			std::make_shared<pots::geometry::segment>(pots::point_d{10, 3, 0}, pots::point_d{10, 0, 0}),
			std::make_shared<pots::geometry::segment>(pots::point_d{10, 0, 0}, pots::point_d{0, 0, 0})
		}
	);

	t_eq_assert(dom.edge(0).lock()->ep(), {0, 3, 0});

	t_eq_assert(dom.p(0, 0), {0, 0, 0});
	t_eq_assert(dom.p(1, 1), {10, 3, 0});
	t_eq_assert(dom.p(0.5, 0.5), {5, 1.5, 0});

	return 0;
}
