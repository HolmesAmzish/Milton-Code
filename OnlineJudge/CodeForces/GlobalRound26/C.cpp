#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        long long num_integer;
        cin >> num_integer;
        vector<long long> array;
        while (num_integer--) {
            long long number;
            cin >> number;
            array.push_back(number);
        }
        long long sum = 0;
        for (int i = 0; i < array.size(); i++) {
            sum += array[i];
            if (i == array.size() || (sum < 0 && array[i + 1] > 0)) {
                sum = abs(sum);
            }
        }
        cout << sum << endl;
    }
    return 0;
}