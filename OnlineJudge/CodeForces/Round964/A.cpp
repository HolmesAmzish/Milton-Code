/**
 * @problem: A+B Again
 * @author: Nulla
 * @date: 2024-08-06
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = n / 10;
        int b = n % 10;
        cout << a + b << endl;
    }
}