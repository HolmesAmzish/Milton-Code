/**
 * Problem: A. Guess the Maximum
 * Date: 2024.06.06
 * Author: Nulla
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INFTY = INT_MAX;

int main() {

    int num_cases;
    cin >> num_cases;

    while (num_cases--) {
        int num_integers;
        cin >> num_integers;
        vector<int> array(num_integers);  // Initialize the vector with the correct size
        for (int i = 0; i < num_integers; i++) {
            cin >> array[i];
        }
        
        int case_max = INFTY;
        for (int i = 0; i < num_integers - 1; i++) {
            int current_max = max(array[i], array[i + 1]);
            case_max = min(case_max, current_max);
        }
        cout << case_max - 1 << endl;
    }
    return 0;
}
