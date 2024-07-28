/**
 * @problem: Duverse Game
 * @author: Nulla
 * @date: 2024-07-18
 * @urls: https://codeforces.com/contest/1994/problem/A
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> a(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> a[i][j];
            }
        }

        if (row == 1 && col == 1) {
            cout << -1 << endl;
            continue;
        }

        // Transform a to b (perform rotation)
        vector<vector<int>> b(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                b[(i+1)%row][(j+1)%col] = a[i][j];
            }
        }

        // Print the rotated matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}