/*
 * Program: topological-sort.cpp
 * Date: 2024.05.26
 * Author: nulla
 * Description:
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MIN_BONUS = 100;

typedef vector<vector<int>> Matrix;

bool topologicalSort(int n,
                     Matrix& adj_list,
                     vector<int>& in_degree,
                     vector<int>& bonuses) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            bonuses[i] = MIN_BONUS;
        }
    }

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj_list[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
                bonuses[v] = bonuses[u] + 1;
            }
        }
    }

    return count == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    Matrix adj_list(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> bonuses(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        in_degree[b]++;
    }

    if (!topologicalSort(n, adj_list, in_degree, bonuses)) {
        cout << "POOR!" << endl;
    } else {
        int total_bonus = 0;
        for (int i = 1; i <= n; ++i) {
            total_bonus += bonuses[i];
        }
        if (total_bonus > 600) total_bonus--;
        cout << total_bonus << endl;
    }

    return 0;
}