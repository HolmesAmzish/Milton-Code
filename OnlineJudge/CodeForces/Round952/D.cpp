#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int max_row_count = 0, max_col_count = 0;
        int best_row = 0, best_col = 0;

        // Find the row with the most #
        for (int i = 0; i < n; i++) {
            int row_count = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    row_count++;
                }
            }
            if (row_count > max_row_count) {
                max_row_count = row_count;
                best_row = i;
            }
        }

        // Find the column with the most #
        for (int j = 0; j < m; j++) {
            int col_count = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == '#') {
                    col_count++;
                }
            }
            if (col_count > max_col_count) {
                max_col_count = col_count;
                best_col = j;
            }
        }

        // Output 1-based indices
        cout << best_row + 1 << ' ' << best_col + 1 << endl;
    }

    return 0;
}
