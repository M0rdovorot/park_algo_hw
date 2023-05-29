#include "MatrixGraph.hpp"

#include <cassert>

MatrixGraph::MatrixGraph(int size): adjacency_matrix_(size, std::vector<bool>(size, 0)) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : adjacency_matrix_(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), 0)) {
        for (int i = 0; i < graph.VerticesCount(); i++) {
            for (auto vertex: graph.GetNextVertices(i)) {
                adjacency_matrix_[i][vertex] = true;
            }
        }
}

MatrixGraph::~MatrixGraph() {}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacency_matrix_.size());
    assert(0 <= to && to < adjacency_matrix_.size());
    adjacency_matrix_[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(adjacency_matrix_.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacency_matrix_.size());
    std::vector<int> next_vertices;
    for (int i = 0; i < adjacency_matrix_.size(); ++i) {
        if (adjacency_matrix_[vertex][i])
            next_vertices.push_back(i);
    }

    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacency_matrix_.size());
    std::vector<int> previous_vertices;
    for (int i = 0; i < adjacency_matrix_.size(); ++i) {
        if (adjacency_matrix_[i][vertex])
            previous_vertices.push_back(i);
    }

    return previous_vertices;
}
