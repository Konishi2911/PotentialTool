/**
* @file domain.hpp
* @auther K.Konishi
* @date Sep.3, 2021
*/
#include "../primitive/point.hpp"
#include "../geometry/curve.hpp"
#include <initializer_list>
#include <vector>
#include <memory>


namespace pots::mesh {

class domain {
private:
	std::vector<point_d> verts_;
	std::vector<std::shared_ptr<geometry::curve>> edges_;

	void init_();

	point_d p1_(double u, double v) const;
	point_d p2_(double u, double v) const;
	point_d p3_(double u, double v) const;

protected:
public:
	domain(const std::vector<std::shared_ptr<geometry::curve>>&);
	domain(std::initializer_list<std::shared_ptr<geometry::curve>>&);

	/**
	* Returns boundary edge at index `i`
	* @param i index of boundary [0, 3].
	* @return the boundary edge specified by argument.
	*/
	std::weak_ptr<geometry::curve> edge(size_t i) const;

	/**
	* Calculates and returns a point at (u, v)
	* @param u a variable of domain coordinate. [0, 1]
	* @param v a variable of domain coordinate. [0, 1]
	* @return the point
	*/
	point_d p(double u, double v) const;
};

}
