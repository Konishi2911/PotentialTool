namespace pots::be {

template<class grid_t>
scalar_d vor_ring_patch<grid_t>::vor_ring_patch(const std::vector<id_type>& eids, const grid_t& ref) :
	patch<grid_t>::patch(eids, ref)
{}



template<class grid_t>
scalar_d vor_ring_patch<grid_t>::intensity() const {
	return this->mag_;
}

template<class grid_t>
void vor_ring_patch<grid_t>::set_intensity(scalar_d mag) const {
	this->mag_ = mag;
}

template<class grid_t>
vector_d vor_ring_patch<grid_t>::influence(const point_d& p) const {
	auto vr = vortex_ring({
		this->mag_,
		this->ref_.nodes()[this->node_ids_[0]].p(),
		this->ref_.nodes()[this->node_ids_[1]].p(),
		this->ref_.nodes()[this->node_ids_[2]].p(),
		this->ref_.nodes()[this->node_ids_[3]].p()
	}
	return vr.influence(p);
}

template<class grid_t>
vector_d vor_ring_patch<grid_t>::dq(const point_d& p) const {
	return this->mag_ * this->influence(p);
}
