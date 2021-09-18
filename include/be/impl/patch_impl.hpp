namespace pots::be {

template<class grid_t>
patch<grid_t>::patch(const std::vector<id_type>& eids, const grid_t& ref):
	mesh::face<grid_t>::face(eids, ref)
{
}


template<class grid_t>
std::vector<point_d> patch<grid_t>::np() const {
	return {
		this->ref_.nodes()[this->nids()[0]].p(), 
		this->ref_.nodes()[this->nids()[1]].p(), 
		this->ref_.nodes()[this->nids()[2]].p(), 
		this->ref_.nodes()[this->nids()[3]].p(), 
	};
}

template<class grid_t>
point_d patch<grid_t>::cp() const {
	auto nids = this->nids();
	return (
		this->ref_.nodes()[nids[0]].p() +
		this->ref_.nodes()[nids[1]].p() +
		this->ref_.nodes()[nids[2]].p() +
		this->ref_.nodes()[nids[3]].p()
	) * 0.25;
}

template<class grid_t>
vector_d patch<grid_t>::n() const {
	auto nids = this->nids();
	auto r1 = vector_d { 
		this->ref_.nodes()[nids[0]].p().x() - this->ref_.nodes()[nids[2]].p().x(),
		this->ref_.nodes()[nids[0]].p().y() - this->ref_.nodes()[nids[2]].p().y(),
		this->ref_.nodes()[nids[0]].p().z() - this->ref_.nodes()[nids[2]].p().z()
	};
	auto r2 = vector_d { 
		this->ref_.nodes()[nids[1]].p().x() - this->ref_.nodes()[nids[3]].p().x(),
		this->ref_.nodes()[nids[1]].p().y() - this->ref_.nodes()[nids[3]].p().y(),
		this->ref_.nodes()[nids[1]].p().z() - this->ref_.nodes()[nids[3]].p().z()
	};
	auto c = r1.cross(r2);
	return c / c.norm();
}

}
