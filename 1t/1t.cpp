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
     MatrixGraph matrix_graph(listGraph);
     SetGraph set_graph(matrix_graph);

     for (int i = 0; i < listGraph.VerticesCount(); i++) {
         for (auto vertex : listGraph.GetNextVertices(i))
             std::cout << vertex << " ";
         std::cout << std::endl;
     }
     std::cout << std::endl;
     for (int i = 0; i < matrix_graph.VerticesCount(); i++) {
         for (auto vertex : matrix_graph.GetNextVertices(i))
             std::cout << vertex << " ";
         std::cout << std::endl;
     }
     std::cout << std::endl;
     for (int i = 0; i < set_graph.VerticesCount(); i++) {
         for (auto vertex : set_graph.GetNextVertices(i))
             std::cout << vertex << " ";
         std::cout << std::endl;
     }
     std::cout << std::endl;
     for (int i = 0; i < arc_graph.VerticesCount(); i++) {
         for (auto vertex : arc_graph.GetNextVertices(i))
             std::cout << vertex << " ";
         std::cout << std::endl;
     }
    return 0;
}