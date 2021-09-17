namespace pots::mesh {

edge::edge(const std::vector<id_type>& nodes)
	: node_ids_(nodes) 
{
}

edge::edge(const std::initializer_list<id_type>& init)
	: node_ids_(init.begin(), init.end()) 
{
}

const std::vector<id_type>& edge::nids() const {
	return this->node_ids_;
}

}
