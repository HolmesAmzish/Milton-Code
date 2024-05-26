/*
 * Program: dijkstra.cpp
 * Date: 2024.05.25
 * Author: nulla
 * Description: 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

const int INFTY = INT_MAX;

typedef unordered_map<char, int> DistanceMap;
typedef unordered_map<char, unordered_map<char, int>> IndexMatrix;

class Graph {
    public:
    void addEdge(char from, char to, int weight);
    DistanceMap dijkstra(char start);

    private:
    IndexMatrix adj_list;
};

void Graph::addEdge(char from, char to, int weight) {
    adj_list[from][to] = weight;
    if(adj_list.find(to) == adj_list.end()) {
        adj_list[to] = unordered_map<char, int>();
    }
}

DistanceMap Graph::dijkstra(char start) {
    DistanceMap distances;

    // Initial adjancency matrix
    for (auto edge : adj_list) {
        distances[edge.first] = INFTY;
    }
    distances[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int current_distance = pq.top().first;
        char current_vertex = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_vertex]) {
            continue;
        }

        for (const auto& neighbour : adj_list[current_vertex]) {
            char neighbour_vertex = neighbour.first;
            int weight = neighbour.second;
            int distance = current_distance + weight;

            if (distance < distances[neighbour_vertex]) {
                distances[neighbour_vertex] = distance;
                pq.push({distance, neighbour_vertex});
            }
        }
    }

    // Sort the result
    for(int i = 0; i < distances.size() - 1; i++) {
        for (int j = i + 1; j < distances.size(); j++) {
            if (distances[i] > distances[j]) {
                swap(distances[i], distances[j]);
            }
        }
    }

    return distances;
}

int main() {
    Graph graph;
    string vertices;
    cin >> vertices;

    // Enter edges information
    char from, to;
    int weight;
    while (cin >> from && from != '#') {
        cin >> to >> weight;
        graph.addEdge(from, to, weight);
    }

    // Find min distances
    char start; cin >> start;
    DistanceMap distances = graph.dijkstra(start);
    for (const auto& vertex : vertices) {
        if (vertex != start) {
            cout << start << vertex << ' ' << distances[vertex] << endl;
        }
    }
    
    return 0;
}