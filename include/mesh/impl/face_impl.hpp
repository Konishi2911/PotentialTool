namespace pots::mesh {

template<class grid_t>
face<grid_t>::face(const std::vector<id_type>& edges, const grid_t& grid)
	: node_ids_(), edge_ids_(edges), rgrid_(grid) 
{
	this->node_ids_ = this->calc_nids_();
}

template<class grid_t>
face<grid_t>::face(const std::initializer_list<id_type>& init, const grid_t& grid)
	: node_ids_(), edge_ids_(init.begin(), init.end()), rgrid_(grid) 
{
	this->node_ids_ = this->calc_nids_();
}

template<class grid_t>
std::vector<id_type> face<grid_t>::nids() const {
	return this->node_ids_;
}

template<class grid_t>
std::vector<id_type> face<grid_t>::eids() const {
	return this->edge_ids_;
}


template<class grid_t>
std::vector<id_type> face<grid_t>::calc_nids_() const {
	auto nids = std::vector<id_type>();
	nids.emplace_back(this->rgrid_.edges()[this->edge_ids_[0]].nids()[0]);
	for (auto i = 1U; i < this->edge_ids_.size(); ++i) {
		auto eid = this->edge_ids_[i];
		auto peid = this->edge_ids_[i - 1];
		if (
			this->rgrid_.edges()[peid].nids()[0] == this->rgrid_.edges()[eid].nids()[0] ||
			this->rgrid_.edges()[peid].nids()[1] == this->rgrid_.edges()[eid].nids()[0]
		) {
			nids.emplace_back(this->rgrid_.edges()[eid].nids()[0]);
		} 
		else {
			nids.emplace_back(this->rgrid_.edges()[eid].nids()[1]);
		}
	}
	return nids;
}

	
}

