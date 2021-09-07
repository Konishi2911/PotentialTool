/**
* @file linear_discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/

#include "discretizer.hpp"
#include "../primitive/types.hpp"
#include "../geometry/segment.hpp"
#include "face.hpp"
#include "edge.hpp"

namespace pots::mesh {

template<class grid_t>
class linear_discretizer: public discretizer<grid_t> {
private:
	std::vector<double> u_dist_() const;
	std::vector<double> v_dist_() const;

protected:
	std::vector<node> nodes_() const override;
	std::vector<typename grid_t::edge_type::source> edges_() const override;
	std::vector<typename grid_t::face_type::source> faces_() const override;

public:
	linear_discretizer(const domain&, size_t, size_t);

};

}

#include "./impl/linear_discretizer_impl.hpp"
