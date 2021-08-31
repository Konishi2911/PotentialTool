#include "../../include/mesh/grid.hpp"
#include <iostream>

int main() {
	pots::mesh::grid grid = pots::mesh::grid::test_case1();

	auto faces = grid.faces();
	if (faces.size() != 20) { 
		std::cerr << "Unexpected face size." << std::endl;
		std::abort(); 
	}
	
	// Internal Face Check
	{
		auto face10 = faces[10];
		auto edges_f10 = face10.eids();
		std::sort(edges_f10.begin(), edges_f10.end());
		auto eids10_expected = std::vector<pots::id_type> { 10, 14, 36, 37 };
		for (auto i = 0U; i < edges_f10.size(); ++i) {
			if (edges_f10[i] != eids10_expected[i]) { 
				std::cerr << "Unexpected edge id was detected. expected " << eids10_expected[i] << " but " << edges_f10[i] << std::endl;
				std::abort(); 
			}		
		}
	}

	// Boundary Face Check
	{ 
		auto face19 = faces[19];
		auto edges_f19 = face19.eids();
		std::sort(edges_f19.begin(), edges_f19.end());
		auto eids19_expected = std::vector<pots::id_type> { 19, 23, 47, 48 };
		for (auto i = 0U; i < edges_f19.size(); ++i) {
			if (edges_f19[i] != eids19_expected[i]) { 
				std::cerr << "Unexpected edge id was detected. expected " << eids19_expected[i] << " but " << edges_f19[i] << std::endl;
				std::abort(); 
			}		
		}
	}


	auto edges = grid.edges();

	// Internal Edge Check
	{
		auto edge = edges[37];
		auto nodes = edge.nids();
		std::sort(nodes.begin(), nodes.end());
		auto nids_expected = std::vector<pots::id_type> { 13, 18 };
		for (auto i = 0U; i < nodes.size(); ++i) {
			if (nodes[i] != nids_expected[i]) {
				std::cerr << "Unexpected node id was detected. expected " << nids_expected[i] << " but " << nodes[i] << std::endl;
				std::abort(); 
			}
		}
	}

	// Boundary Edge Check
	{
		auto edge = edges[23];
		auto nodes = edge.nids();
		std::sort(nodes.begin(), nodes.end());
		auto nids_expected = std::vector<pots::id_type> { 28, 29 };
		for (auto i = 0U; i < nodes.size(); ++i) {
			if (nodes[i] != nids_expected[i]) {
				std::cerr << "Unexpected node id was detected. expected " << nids_expected[i] << " but " << nodes[i] << std::endl;
				std::abort(); 
			}
		}
	}

	return 0;
}
