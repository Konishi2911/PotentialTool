namespace pots::mesh {
	
template<class grid_t>
grid_t discretizer<grid_t>::create_grid() const {
	return grid_t {this->nodes_(), this->edges_(), this->faces_()};
}

}
