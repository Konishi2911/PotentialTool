namespace pots::mesh {

template<class grid_t, class edge_t, class face_t>
grid<grid_t, edge_t, face_t>::grid(
	const std::vector<node>& nodes, 
	const std::vector<std::vector<id_type>>& edge_source,
	const std::vector<std::vector<id_type>>& face_source
) :
	faces_(),
	edges_(),
	nodes_(nodes)
{
	for (auto es: edge_source) {
		this->edges_.emplace_back(es);
	}
	for (auto fs: face_source) {
		this->faces_.emplace_back(fs, static_cast<const grid_t&>(*this));
	}
}


template<class grid_t, class edge_t, class face_t>
const std::vector<face_t>& grid<grid_t, edge_t, face_t>::faces() const {
	return this->faces_;
}

template<class grid_t, class edge_t, class face_t>
const std::vector<edge_t>& grid<grid_t, edge_t, face_t>::edges() const {
	return this->edges_;
}

template<class grid_t, class edge_t, class face_t>
const std::vector<node>& grid<grid_t, edge_t, face_t>::nodes() const {
	return this->nodes_;
}

}

