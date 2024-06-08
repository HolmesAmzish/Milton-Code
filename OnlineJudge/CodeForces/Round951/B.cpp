/**
 * Problem: B. XOR Sequences
 * Date: 2024.06.06
 * Author: Nulla
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find the length of the longest common subsegment
int longestCommonSubsegment(int x, int y) {
    int z = x ^ y; // XOR of x and y to find differing bits
    int length = 0;
    // Count the number of trailing zero bits in z
    while (z > 0) {
        length++;
        z >>= 1;
    }
    return pow(2, (length - 1));
}

int main() {

    int num_cases;
    cin >> num_cases;
    vector<int> results(num_cases);
    for (int i = 0; i < num_cases; ++i) {
        int x, y;
        cin >> x >> y;
        results[i] = longestCommonSubsegment(x, y);
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}
