#pragma once 

#include "../mesh/face.hpp"

namespace pots::be {

class patch: mesh::face {
private:
protected:
public:
	point_d cnt_point() const;
};

}
