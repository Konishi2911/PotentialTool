#include "../../include/be/vortex_segment.hpp"
#include <iostream>

bool equal_f(double a, double b) {
	return std::abs(a - b) < 1e-10;
}

int main() {
	auto gamma = 1.0;
	auto p1 = pots::point_d { 0.0, 0.0, 0.0 };
	auto p2 = pots::point_d { 0.0, 1.0, 0.0 };

	auto p_probe = pots::point_d { 1.0, 0.5, 0 };

	auto v_seg = pots::be::vortex_segment(gamma, p1, p2);

	auto dq = v_seg.dq(p_probe);

	if (!equal_f(dq.norm(), 0.07117625434)) { 
		std::cerr << "Equal assertion failure. Expected " << 0.07117625434 << " but " << dq.norm() << std::endl;
		std::abort(); 
	}		
}
