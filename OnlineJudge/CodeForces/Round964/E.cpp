/**
 * @problem: Triple Operations
 * @author: Nulla
 * @date: 2024-08-07
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        priority_queue<int> pq;
        for (int i = l; i <= r; i++) {
            pq.push(i);
        }

        int operations = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x == 0 && y == 0) break;

            pq.push(3 * x);
            pq.push(y / 3);

            operations++;
        }

        // Handle the case where only one element remains in the queue
        while (!pq.empty() && pq.top() != 0) {
            int x = pq.top();
            pq.pop();
            pq.push(x / 3);
            operations++;
        }

        cout << operations << endl;
    }
    return 0;
}
