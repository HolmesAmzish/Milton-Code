/**
 * Problem: transform roman number to integers
 * Date: 2024-10-18
 * Author: Holmes Amzish
 */
#include <unordered_map>

using namespace std;

class Solution {

    public int romanToInt(String s) {
        unordered_map<char, int> roman_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int pre_value = 0;
        int total_value = 0;
        for (char c : s) {
            int current_value = roman_map[c];
            if (current_value > pre_value && pre_value != 0) {
                total_value += current_value - 2 * pre_value;
            } else {
                total_value += current_value;
            }
            pre_value = current_value;
        }
        return total_value;
    }
}