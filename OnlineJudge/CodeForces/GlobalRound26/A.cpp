#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool all_same = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                all_same = false;
                break;
            }
        }
        
        if (all_same) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            string result(n, 'B');
            result[0] = 'R';
            cout << result << endl;
        }
    }
    return 0;
}
