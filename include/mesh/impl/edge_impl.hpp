namespace pots::mesh {

template<class grid_t>
edge<grid_t>::edge(const std::vector<id_type>& nodes, const grid_t& grid)
	: node_ids_(nodes), rgrid_(grid) 
{
}

template<class grid_t>
edge<grid_t>::edge(const std::initializer_list<id_type>& init, const grid_t& grid)
	: node_ids_(init.begin(), init.end()), rgrid_(grid) 
{
}

template<class grid_t>
std::vector<id_type> edge<grid_t>::nids() const {
	return this->node_ids_;
}

}
