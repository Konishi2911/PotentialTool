#include "../../include/mesh/node.hpp"

namespace pots::mesh {

node::node(const point_d& p): p_(p) {}

const point_d& node::p() const { return this->p_; }

}
