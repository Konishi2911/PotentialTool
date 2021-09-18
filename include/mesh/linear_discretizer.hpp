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

class linear_discretizer: public discretizer {
private:
	std::vector<double> u_dist_() const;
	std::vector<double> v_dist_() const;

protected:
	std::vector<node> nodes_() const override;
	std::vector<std::vector<id_type>> edge_sources_() const override;
	std::vector<std::vector<id_type>> face_sources_() const override;

public:
	linear_discretizer(const domain&, size_t, size_t);

};

}

#include "./impl/linear_discretizer_impl.hpp"
