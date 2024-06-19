#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> array(n);
        vector<long long> prefix_sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> array[i];
            prefix_sum[i + 1] = prefix_sum[i] + array[i];
        }

        int good_prefix_count = 0;

        for (int i = 0; i < n; i++) {
            long long current_sum = prefix_sum[i + 1];
            for (int j = 0; j <= i; j++) {
                if (array[j] == current_sum - array[j]) {
                    good_prefix_count++;
                    break;
                }
            }
        }

        cout << good_prefix_count << endl;
    }

    return 0;
}
