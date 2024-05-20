#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
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
    unordered_map<char, int> vertex_map;

public:
    void CreateGraph(const string& sequence) {
        int index = 0;
        for (char v : sequence) {
            if (v != '!') {
                vertices.push_back(Vertex(v));
                vertex_map[v] = index++;
            }
        }
        InitializeAdjMatrix();
    }

    void InitializeAdjMatrix() {
        int n = vertices.size();
        adj_matrix.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            adj_matrix[i][i] = 0;
        }
    }

    void AddEdge(int x, int y, int weight) {
        adj_matrix[x][y] = weight;
        adj_matrix[y][x] = weight;
    }

    void PrimMst(char start) {
        int n = vertices.size();
        int start_index = vertex_map[start];
        vertices[start_index].distance = 0;
        int total_weight = 0;

        for (int count = 0; count < n; count++) {
            int min_dist = INF, min_node = -1;

            // Find the node who has the min distance
            for (int current_node = 0; current_node < n; current_node++) {
                if (!vertices[current_node].selected
                && vertices[current_node].distance < min_dist) {
                    min_dist = vertices[current_node].distance;
                    min_node = current_node;
                }
            }
            vertices[min_node].selected = true;

            // Print the choosen node
            if(vertices[min_node].parent_index != -1) {
                cout << vertices[vertices[min_node].parent_index].value
                << vertices[min_node].value << " "
                << adj_matrix[min_node][vertices[min_node].parent_index] << endl;
                total_weight += adj_matrix[min_node][vertices[min_node].parent_index];
            }

            // Update information for next scan
            for (int i = 0; i < n; i++) {
                if (adj_matrix[min_node][i] != INF
                && !vertices[i].selected
                && adj_matrix[min_node][i] < vertices[i].distance) {
                    vertices[i].parent_index = min_node;
                    vertices[i].distance = adj_matrix[min_node][i];
                }
            }
        }
    
        cout << total_weight << endl;
    }

};

int main() {
    string sequence;
    cin >> sequence;

    Graph graph;
    graph.CreateGraph(sequence);
    
    int x, y, w;
    while (true) {
        cin >> x;
        if (x == -1) break;
        cin >> y >> w;
        graph.AddEdge(x, y, w);
    }

    char start_vertex;
    cin >> start_vertex;
    
    graph.PrimMst(start_vertex);

    return 0;
}