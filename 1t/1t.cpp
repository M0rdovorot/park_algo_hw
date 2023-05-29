#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cassert>

#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"

void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::function<void(int)>& func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex : graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void BFS(const IGraph& graph, std::function<void(int)> func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            BFS(graph, i, visited, func);
    }
}

void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::function<void(int)>& func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex : graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, func);
    }
}

void DFS(const IGraph& graph, std::function<void(int)> func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            DFS(graph, i, visited, func);
    }
}

int main(int argc, const char* argv[]) {
    ListGraph listGraph(9);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    listGraph.AddEdge(7, 8);

     ArcGraph arc_graph(listGraph);
     MatrixGraph matrix_graph(arc_graph);
     SetGraph set_graph(matrix_graph);

     BFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     DFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     std::cout << std::endl;


     BFS(arc_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     DFS(arc_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     std::cout << std::endl;

     BFS(matrix_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     DFS(matrix_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     std::cout << std::endl;

     BFS(set_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     DFS(set_graph, [](int vertex) { std::cout << vertex << " "; });
     std::cout << std::endl;
     std::cout << std::endl;

     //for (int i = 0; i < listGraph.VerticesCount(); i++) {
     //    for (auto vertex : listGraph.GetNextVertices(i))
     //        std::cout << vertex << " ";
     //    std::cout << std::endl;
     //}
     //std::cout << std::endl;
     //for (int i = 0; i < matrix_graph.VerticesCount(); i++) {
     //    for (auto vertex : matrix_graph.GetNextVertices(i))
     //        std::cout << vertex << " ";
     //    std::cout << std::endl;
     //}
     //std::cout << std::endl;
     //for (int i = 0; i < set_graph.VerticesCount(); i++) {
     //    for (auto vertex : set_graph.GetNextVertices(i))
     //        std::cout << vertex << " ";
     //    std::cout << std::endl;
     //}
     //std::cout << std::endl;
     //for (int i = 0; i < arc_graph.VerticesCount(); i++) {
     //    for (auto vertex : arc_graph.GetNextVertices(i))
     //        std::cout << vertex << " ";
     //    std::cout << std::endl;
     //}
    return 0;
}