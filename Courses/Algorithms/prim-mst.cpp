/*
 * Program: prim-mst.cpp
 * Date: 2024.05.19
 * Author: Nulla
 * Repository: Milton-Code
 * Description: Find the minimum tree by prim algorithm
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Vertex {
    char value;
    bool selected;
    int distance;
    int parent_index;

    Vertex(char x) : value(x), selected(false), distance(INF), parent_index(-1) {}
};

class Graph {
    private:
    vector<Vertex> vertices;
    vector<vector<int>> adj_matrix;

    public:
    void CreateGraph(string& sequence) {
        for (char v : sequence) {
            if (v != '!') {
                vertices.push_back(Vertex(v));
            }
        }
        InitialAdjMatrix();
    }

    void InitialAdjMatrix() {
        int n = vertices.size();
        adj_matrix.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            adj_matrix[i][i] = 0;
        }
    }

    void AddEdge(int x, int y, int weight) {
        adj_matrix[x][y] = weight;
        adj_matrix[x][y] = weight;
    }

    void PrimMst() {
        int n = vertices.size();
        vertices[0].distance = 0;
        // Start from index 0

        for (int count = 0; count < n - 1; count++) {
            int min_dist = INF, min_node;
            for (int current_node = 0; current_node < n; current_node++) {
                if (!vertices[current_node].selected && vertices[current_node].distance < min_dist) {
                    min_dist = vertices[current_node].distance;
                    min_node = current_node;
                }
            }

            vertices[min_node].selected = true;

            // Update distances of adjacent vertices
            for (int i = 0; i < n; i++) {
                if (adj_matrix[min_node][i] && 
                    !vertices[i].selected && 
                    adj_matrix[min_node][i] < vertices[i].distance) {
                    vertices[i].parent_index = min_node;
                    vertices[i].distance = adj_matrix[min_node][i];
                }
            }
        }

        // Print the MST
        int total_weight = 0;
        for (int i = 1; i < n; ++i) {
            cout << vertices[vertices[i].parent_index].value << " " << vertices[i].value << "\t" << adj_matrix[i][vertices[i].parent_index] << "\n";
            total_weight += adj_matrix[i][vertices[i].parent_index];
        }
        cout << "Total weight of MST: " << total_weight << endl;
    }
};

int main() {
    string sequence;
    cin >> sequence;

    Graph graph;
    graph.CreateGraph(sequence);
    
    int x, y, w;
    while(true) {
        cin >> x;
        if (x == -1) break;
        cin >> y >> w;
        graph.AddEdge(x, y, w);
    }

    graph.PrimMst();

    return 0;
}