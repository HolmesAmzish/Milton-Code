/**
 * @problem: Find if digit game can be won
 * @date: 2024-07-30
 * @author: Nulla
 */

class Solution {
    public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0, twoDigitSum = 0;
        for (int num : nums) {
            if (num < 10) {
                singleDigitSum += num;
            } else {
                twoDigitSum += num;
            }
        }
        return singleDigitSum != twoDigitSum;
    }
};