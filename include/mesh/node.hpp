#pragma once

#include "../primitive/point.hpp"

namespace pots::mesh {

class node {
private:
	point_d p_;
protected:
public:
	node(const point_d& p);

	const point_d& p() const;
};

}
