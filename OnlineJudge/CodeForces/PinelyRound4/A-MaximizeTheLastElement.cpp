#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            if (i % 2 == 0) {
                max = max > num ? max : num;
            }
        }
        cout << max << endl;
    }
    return 0;
}