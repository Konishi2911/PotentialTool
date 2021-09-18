namespace pots::mesh {

template<class grid_t>
edge<grid_t>::edge(const std::vector<id_type>& nodes, const grid_t& ref) : 
	node_ids_(nodes),
	ref_(ref)
{
}


template<class grid_t>
const std::vector<id_type>& edge<grid_t>::nids() const {
	return this->node_ids_;
}

}
