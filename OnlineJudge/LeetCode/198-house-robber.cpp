/**
 * Problem:
 * Date: 2024.06.25
 * Author:
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;
        if (length == 1) return nums[0];
        
        vector<int> max_values(length);
        max_values[0] = nums[0];
        max_values[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < length; i++) {
            max_values[i] = max(max_values[i - 1], nums[i] + max_values[i - 2]);
        }
        
        return max_values[length - 1];
    }
};
