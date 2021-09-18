namespace pots::mesh {

template<class grid_t>
face<grid_t>::face(const std::vector<id_type>& eids, const grid_t& grid): 
	node_ids_(this->calc_nids_(eids, grid)), 
	edge_ids_(eids),
	ref_(grid)
{
}


template<class grid_t>
const std::vector<id_type>& face<grid_t>::nids() const {
	return this->node_ids_;
}

template<class grid_t>
const std::vector<id_type>& face<grid_t>::eids() const {
	return this->edge_ids_;
}


template<class grid_t>
std::vector<id_type> face<grid_t>::calc_nids_(const std::vector<id_type>& eids, const grid_t& ref) {
	auto nids = std::vector<id_type>();
	nids.emplace_back(ref.edges()[eids[0]].nids()[0]);
	for (auto i = 1U; i < eids.size(); ++i) {
		auto eid = eids[i];
		auto peid = eids[i - 1];
		if (
			ref.edges()[peid].nids()[0] == ref.edges()[eid].nids()[0] ||
			ref.edges()[peid].nids()[1] == ref.edges()[eid].nids()[0]
		) {
			nids.emplace_back(ref.edges()[eid].nids()[0]);
		} 
		else {
			nids.emplace_back(ref.edges()[eid].nids()[1]);
		}
	}
	return nids;
}

	
}

