/*
 * File:        complete-binary-tree.cpp
 * Date:        2024.04.21
 * Author:      Nulla
 * Description: build a binary tree by inputing a string
 *              display the binary tree by level order
 *              judge whether it is a complete binary tree
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *left, *right;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(const string &tree, int &index) {
    if (index >= tree.length() || tree[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode *node = new TreeNode(tree[index]);
    index++;
    node->left = BuildTree(tree, index);
    node->right = BuildTree(tree, index);
    return node;
}

bool isCompleteTree(TreeNode *root) {
    if (root == nullptr)
        return true;

    queue<TreeNode*> level;
    level.push(root);
    bool reached = false;

    while (!level.empty()) {
        TreeNode* current_node = level.front();
        level.pop();
        
        if (reached && current_node != nullptr)
            return false;

        if (current_node == nullptr) {
            reached = true;
            continue; // Skip to next iteration
        }

        level.push(current_node->left);
        level.push(current_node->right);
    }

    return true;
}

void PrintTree(TreeNode *root) {
    queue<TreeNode*> level;
    level.push(root);
    
    while (!level.empty()) {
        TreeNode *current_node = level.front();
        level.pop();
        cout << current_node->data;
        if (current_node->left != nullptr)
            level.push(current_node->left);
        if (current_node->right != nullptr)
            level.push(current_node->right);
    }
    cout << endl;
}

int main(void) {
    //string test_sample = "AB#C##DE#F###";
    string tree;
    cin >> tree;
    int i = 0;
    TreeNode* root = BuildTree(tree, i);
    PrintTree(root);
    if (isCompleteTree(root)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
