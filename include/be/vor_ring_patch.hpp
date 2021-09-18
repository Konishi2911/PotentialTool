/**
* @auther K.Konishi
* @date Sep.3, 2021
*/
#include "patch.hpp"

namespace pots::be {

template<class grid_t>
class vor_ring_patch: public patch, public element {
private:
	scalar_d mag_;	

protected:
public:
	vor_ring_patch(const std::vector<id_type>& eids, const grid_t& ref);


 	// -- Inherited Member Functions -- //

	scalar_d intensity() const override;	
	void set_intensity(scalar_d) override;	

	vector_d influence(const point_d&) const override;
	vector_d dq(const point_d&) const override;
};

}

#include "impl/vor_ring_patch_imol.hpp"
