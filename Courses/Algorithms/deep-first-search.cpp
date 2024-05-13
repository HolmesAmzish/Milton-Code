/*
 * Program: deep-first-search.cpp
 * Date: 2024.05.12
 * Author: Nulla
 * Description: store the information of graph in to a adj matrix
 *              find wheather these is a path from A to B
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
    }

    void DisplayMap() {
        for (int i = 0; i < vertices.size(); i++) {
            for (int j = 0; j < vertices.size(); j++) {
                cout << (matrix[i][j] ? 1 : 0) << ' ';
            }
            cout << '\n';
        }
    }

    void DeepFirstSearch(int i) {
        vertices[i].visited = true;
        for (int j = 0; j < vertices.size(); j++) {
            if (matrix[i][j] == true && vertices[j].visited == false) {
                DeepFirstSearch(j);
            }
        }
    }

    bool hasPath(char start, char target) {
        int start_index = -1;
        for (int index = 0; index < vertices.size(); index++) {
            if (vertices[index].value == start) {
                start_index = index;
                break;
            }
        }

        // Return false if there is no vertx match the input
        if (start_index == -1)
            return false;

        DeepFirstSearch(start_index);

        for (Vertex& vertex : vertices) {
            if (vertex.value == target && vertex.visited == true) {
                return true;
            }
        }
        return false;
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

    char start, target;
    cin >> start >> target;
    graph.DisplayMap();
    cout << (graph.hasPath(start, target) ? 'T' : 'F') << endl;

    return 0;
}