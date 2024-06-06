/**
 * Problem: 11. Container with most water
 * Date: 2024.06.05
 * Author: Nulla
 * OnlineJudge: LeetCode
*/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0; // Pointer to the beginning of the array
        int right = height.size() - 1; // Pointer to the end of the array
        int max_storage = 0; // Variable to keep track of the maximum area

        while (left < right) {
            // Calculate the current area with the two pointers
            int current_storage = std::min(height[left], height[right]) * (right - left);
            
            // Update the maximum area if the current area is larger
            max_storage = std::max(max_storage, current_storage);
            
            // Move the pointers: increment left if the left height is less than the right height, otherwise decrement right
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_storage; // Return the maximum area found
    }
};