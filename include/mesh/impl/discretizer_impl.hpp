namespace pots::mesh {
	
template<class grid_t>
grid_t discretizer::create_grid() const {
	return grid_t {this->nodes_(), this->edge_sources_(), this->face_sources_()};
}

}
