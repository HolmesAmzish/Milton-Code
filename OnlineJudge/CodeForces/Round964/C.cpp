/**
 * @problem: Showering
 * @author: Nulla
 * @date: 2024-08-06
 */

#include <iostream>
#include <vector>

using namespace std;

struct Task {
    int l;
    int r;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numOfTasks, showerTime, maxTime;
        cin >> numOfTasks >> showerTime >> maxTime;
        vector<Task> tasks(numOfTasks);
        for (int i = 0; i < numOfTasks; i++) {
            cin >> tasks[i].l >> tasks[i].r;
        }

        bool canShower = false;

        // Check time before the first task
        if (tasks[0].l >= showerTime) {
            canShower = true;
        }

        // Check time between tasks
        for (int i = 1; i < numOfTasks; i++) {
            if (tasks[i].l - tasks[i - 1].r >= showerTime) {
                canShower = true;
            }
        }

        // Check time after the last task
        if (maxTime - tasks[numOfTasks - 1].r >= showerTime) {
            canShower = true;
        }

        if (canShower) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
