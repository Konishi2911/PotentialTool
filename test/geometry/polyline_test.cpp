#include "../../include/geometry/polyline.hpp"
#include <iostream>

bool equal(int a, int b) {
	return a == b;
}
bool equal(double a, double b) {
	return std::abs(a - b) < 1e-10;
}
template<typename T>
bool equal(const pots::point<T>& p1, const pots::point<T>& p2) {
	return 
		equal(p1.x(), p2.x()) && 
		equal(p1.y(), p2.y()) && 
		equal(p1.z(), p2.z());
}


void t_eq_assert(int t1, int t2) {
	if (!equal(t1, t2)) {
		std::cerr << "Equal assertion failure. Expected " << t2 << " but " << t1 << std::endl;
		std::abort();
	}
}

void t_eq_assert(double t1, double t2) {
	if (!equal(t1, t2)) {
		std::cerr << "Equal assertion failure. Expected " << t2 << " but " << t1 << std::endl;
		std::abort();
	}
}

template<typename T>
void t_eq_assert(const pots::point<T>& t1, const pots::point<T>& t2) {
	if (!equal(t1, t2)) {
		std::cerr << "Equal assertion failure. Expected " 
			<< "{ " << t2.x() << ", " << t2.y() << ", " << t2.z() << " }"
			<< " but "
			<< "{ " << t1.x() << ", " << t1.y() << ", " << t1.z() << " }"
			<< std::endl;
		std::abort();
	}
}

int main() {
	auto pl1 = pots::geometry::polyline{ {0, 0, 0}, {10, 0, 0}, {10, 5, 0} };	
	t_eq_assert(pl1.length(), 15.0);
	t_eq_assert(pl1.p(0.5), {7.5, 0, 0});
	t_eq_assert(pl1.p(0.9), {10, 3.5, 0});
	t_eq_assert(pl1.sp(), {0, 0, 0});
	t_eq_assert(pl1.ep(), {10, 5, 0});
}
