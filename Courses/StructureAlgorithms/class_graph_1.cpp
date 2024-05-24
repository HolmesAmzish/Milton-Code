/*
 *          File: class_graph_1.cpp
 *       Program: Adjacency weighted directed graph
 *          Date: 2024.05.24
 *        Author: Nulla
 *   Description: Create a graph by adjacency matrix     
 * 
 */

#include <iostream>
using namespace std;

class AdjacencyWDigraph {
    protected:
    int number_;
    int edge_;
    char **adj_matrix_;
    char no_edge_;

    public:
    // Constractor
    AdjacencyWDigraph(int number_of_vertices = 0, char the_no_edge = 0) {
        if (number_of_vertices < 0)
        throw illegalParameterValue("number of vertices must be >= 0");
        number_ = number_of_vertices;
        edge_ = 0;
        no_edge_ = the_no_edge;
        make2dArray(adj_matrix_, number_ + 1, number_ + 1);
        for (int i = 1; i <= number_; i++) {
            fill(adj_matrix_[i], adj_matrix_[i] + n + 1, no_edge_);
        }
    }
}