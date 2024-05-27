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
#include <algorithm>
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
    if (adj_list.find(to) == adj_list.end()) {
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

    while (!pq.empty()) {
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
    char start;
    cin >> start;
    DistanceMap distances = graph.dijkstra(start);

    // Convert DistanceMap to vector<pair<char, int>>
    vector<pair<char, int>> sortedDistances(distances.begin(), distances.end());

    // Sort the vector by value
    sort(sortedDistances.begin(), sortedDistances.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    });

    // Output sorted distances
    for (const auto& pair : sortedDistances) {
        if (pair.first != start) {
            cout << start << pair.first << ' ' << pair.second << endl;
        }
    }

    return 0;
}
