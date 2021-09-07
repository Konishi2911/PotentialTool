namespace pots::mesh {

template<class grid_t>
face<grid_t>::face(const std::vector<id_type>& edges, const grid_t& grid)
	: edge_ids_(edges), rgrid_(grid) 
{
}

template<class grid_t>
face<grid_t>::face(const std::initializer_list<id_type>& init, const grid_t& grid)
	: edge_ids_(init.begin(), init.end()), rgrid_(grid) 
{
}


template<class grid_t>
std::vector<id_type> face<grid_t>::eids() const {
	return this->edge_ids_;
}
	
}

