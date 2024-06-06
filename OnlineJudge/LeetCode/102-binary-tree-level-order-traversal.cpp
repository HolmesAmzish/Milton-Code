/**
 * Problem: Binary Tree level order traversal
 * Date: 2024.06.04
 * Author: Nulla
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) return results;

        queue<TreeNode*> current_level, next_level;
        

        next_level.push(root);
        while (!next_level.empty()) {
            swap(current_level, next_level);
            vector<int> current_level_values;

            while (!current_level.empty()) {
                TreeNode* current_node = current_level.front();

                current_level_values.push_back(current_node->val);
                if (current_node->left != nullptr)
                    next_level.push(current_node->left);
                if (current_node->right != nullptr)
                    next_level.push(current_node->right);

                current_level.pop();
            }
            results.push_back(current_level_values);
        }
        return results;
    }
};