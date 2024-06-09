#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        long long number;
        cin >> number;
        vector<int> array;
        while (number) {
            int digit = number % 10;
            array.push_back(digit);
            number /= 10;
        }
        if (array.back() > 1 || array.front() == 9) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
