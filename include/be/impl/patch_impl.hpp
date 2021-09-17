namespace pots::be {

template<class grid_t>
patch::patch(const std::vector<id_type>& eids, const grid_t& ref):
	mesh::face::face(eids, ref)
{
}


template<class grid_t>
std::vector<point_d> patch::np(const grid_t& ref) const {
	return {
		ref.nodes()[this->nids()[0]].p(), 
		ref.nodes()[this->nids()[1]].p(), 
		ref.nodes()[this->nids()[2]].p(), 
		ref.nodes()[this->nids()[3]].p(), 
	};
}

template<class grid_t>
point_d patch::cp(const grid_t& ref) const {
	auto nids = this->nids();
	return (
		ref.nodes()[nids[0]].p() +
		ref.nodes()[nids[1]].p() +
		ref.nodes()[nids[2]].p() +
		ref.nodes()[nids[3]].p()
	) * 0.25;
}

template<class grid_t>
vector_d patch::n(const grid_t& ref) const {
	auto nids = this->nids();
	auto r1 = vector_d { 
		ref.nodes()[nids[0]].p().x() - ref.nodes()[nids[2]].p().x(),
		ref.nodes()[nids[0]].p().y() - ref.nodes()[nids[2]].p().y(),
		ref.nodes()[nids[0]].p().z() - ref.nodes()[nids[2]].p().z()
	};
	auto r2 = vector_d { 
		ref.nodes()[nids[1]].p().x() - ref.nodes()[nids[3]].p().x(),
		ref.nodes()[nids[1]].p().y() - ref.nodes()[nids[3]].p().y(),
		ref.nodes()[nids[1]].p().z() - ref.nodes()[nids[3]].p().z()
	};
	auto c = r1.cross(r2);
	return c / c.norm();
}

}
