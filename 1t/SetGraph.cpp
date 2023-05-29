#include <cassert>

#include "SetGraph.hpp"

SetGraph::SetGraph(int size): adjance_set_(size) {}

SetGraph::SetGraph(const IGraph& graph) : adjance_set_(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        for (auto vertex : graph.GetNextVertices(i)) {
            adjance_set_[i].insert(vertex);
        }
    }
}

SetGraph::~SetGraph() {
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjance_set_.size());
    assert(0 <= to && to < adjance_set_.size());
    adjance_set_[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjance_set_.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjance_set_.size());
    std::vector<int> next_vertices;
    for (auto it = adjance_set_[vertex].begin(); it != adjance_set_[vertex].end(); it++) {
        next_vertices.push_back(*it);
    }
    return next_vertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjance_set_.size());
    std::vector<int> previous_vertices;
    for (int i = 0; i < adjance_set_.size(); ++i) {
        if (adjance_set_[i].contains(vertex)) {
            previous_vertices.push_back(i);
        }
    }
    return previous_vertices;
}
