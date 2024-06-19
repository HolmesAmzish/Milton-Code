#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max = 0, max_x = 2;
        for (int x = 2; x <= n; x++) {
            int sum = (n / x) * x * (1 + (n / x)) / 2;
            if (sum > max) {
                max = sum;
                max_x = x;
            }
        }
        cout << max_x << endl;
    }
    return 0;//
}