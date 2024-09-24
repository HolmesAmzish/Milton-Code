/**
 * problem: Number of 
 * date: 2024-09-21
 * author: cacc
 */

#include <iostream>

using namespace std;

int main() {
    int number = 78120;
    int count = 0;
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) count++;
    }
    cout << count << endl;
    return 0;
}