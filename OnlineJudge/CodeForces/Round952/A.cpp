#include <iostream>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        string string_a, string_b;
        cin >> string_a >> string_b;
        swap(string_a[0], string_b[0]);
        cout << string_a << ' ' << string_b << endl;
    }
    return 0;
}