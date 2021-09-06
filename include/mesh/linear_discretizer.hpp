/**
* @file linear_discretizer.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/

#include "discretizer.hpp"

namespace pots::mesh {

template<class edge_t, class face_t>
class linear_discretizer: discretizer<edge_t, face_t> {
private:
	std::vector<double> u_dist_();
	std::vector<double> v_dist_();

protected:
public:
	using discretizer::discretizer;

	std::vector<node> nodes() const override;
	std::vector<edge_t> edges() const override;
	std::vector<face_t> faces() const override;

};

}

#include "./impl/linear_discretizer.hpp"
