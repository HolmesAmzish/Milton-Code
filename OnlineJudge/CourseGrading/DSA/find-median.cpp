/*
 * Program: find-median.cpp
 * Date: 2024.06.02
 * Author: Nulla
 * Description: Find the median of two sorted arrays of equal length.
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& array) {
    for (int i : array) {
        cout << i << ' ';
    }
    cout << endl;
}

int findMedian(vector<int> array[2], int number) {
    if (number == 1) {
        return min(array[0][0], array[1][0]);
    }

    int median[2];
    median[0] = array[0][(number % 2 == 1) ? number / 2 : (number - 1) / 2];
    median[1] = array[1][(number % 2 == 1) ? number / 2 : (number - 1) / 2];

    if (median[0] == median[1]) {
        return median[0];
    } else {
        if (median[0] < median[1]) {
            array[0].erase(array[0].begin(), array[0].begin() + number / 2);
            array[1].erase(array[1].begin() + (number + 1) / 2, array[1].end());
        } else {
            array[1].erase(array[1].begin(), array[1].begin() + number / 2);
            array[0].erase(array[0].begin() + (number + 1) / 2, array[0].end());
        }
        printArray(array[0]);
        printArray(array[1]);

        number = (number + 1) / 2; 
        return findMedian(array, number);
    }
}

int main() {
    int number, input;
    cin >> number;
    vector<int> array[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < number; ++j) {
            cin >> input;
            array[i].push_back(input);
        }
    }

    int result = findMedian(array, number);
    cout << "mid=" << result << endl;

    return 0;
}
