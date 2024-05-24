/*
 * Program: connected-components.cpp
 * Date: 2024.05.13
 * Author: Nulla
 * Description: 
 */

#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    char value;
    bool visited;
    Vertex(char v) : value(v), visited(false) {}
};

class Graph {
    private:
    vector<Vertex> vertices;
    vector<vector<bool>> matrix;

    public:
    void CreateGraph(string sequence) {
        for(char v : sequence) {
            if (v == '!') break;
            Vertex vertex(v);
            vertices.push_back(vertex);
        }
        int size = vertices.size();
        matrix.resize(size, vector<bool>(size, false));
    }

    void CreateMap(int i, int j) {
        matrix[i][j] = true;
        matrix[j][i] = true;
    }

    void DeepFirstSearch(int i) {
        vertices[i].visited = true;
        for (int j = 0; j < vertices.size(); j++) {
            if (matrix[i][j] == true && vertices[j].visited == false) {
                DeepFirstSearch(j);
            }
        }
    }

    int CountComponents() {
        for (Vertex vertex : vertices) {
            vertex.visited = false;
        }

        int count = 0;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].visited == false) {
                DeepFirstSearch(i);
                count++;
            }
        }
        return count;
    }
};

int main() {
    string sequence;
    cin >> sequence;
    Graph graph;
    graph.CreateGraph(sequence);

    while(true) {
        int vertex_1, vertex_2;
        cin >> vertex_1 >> vertex_2;
        if (vertex_1 == -1 || vertex_2 == -1)
            break;
        graph.CreateMap(vertex_1, vertex_2);
    }

    cout << graph.CountComponents() << endl;

    return 0;
}