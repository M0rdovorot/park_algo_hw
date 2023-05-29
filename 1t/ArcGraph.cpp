#include "ArcGraph.hpp"

#include <cassert>

ArcGraph::ArcGraph(int size): vertices_(size) {}

ArcGraph::ArcGraph(const IGraph& graph): vertices_(graph.VerticesCount()) {
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		for (auto vertex : graph.GetNextVertices(i)) {
			edges_.push_back({i, vertex});
		}
	}
}

ArcGraph::~ArcGraph() {}

void ArcGraph::AddEdge(int from, int to) {
	assert(0 <= from && from < edges_.size());
	assert(0 <= to && to < edges_.size());
	edges_.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
	return vertices_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
	assert(0 <= vertex && vertex < edges_.size());
	std::vector<int> next_verices;
	for (auto edge : edges_) {
		if (edge.first == vertex)
			next_verices.push_back(edge.second);
	}
	return next_verices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
	assert(0 <= vertex && vertex < edges_.size());
	std::vector<int> previous_verices;
	for (auto edge : edges_) {
		if (edge.second == vertex)
			previous_verices.push_back(edge.first);
	}
	return previous_verices;
}
