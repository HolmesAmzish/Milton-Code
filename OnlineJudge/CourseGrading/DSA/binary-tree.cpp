/*
 * Program:     binary-tree.cpp
 * Date:        2024.04.20
 * Author:      Nulla
 * Description: input a binary tree, 
 *              swap the child tree who has the same height, 
 *              count the balanced node
 */

#include <iostream>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *left, *right;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(const string& input, int& index) {
    if (index >= input.length() || input[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(input[index]);
    index++;
    node->left = BuildTree(input, index);
    node->right = BuildTree(input, index);
    return node;
}

void PrintTree(TreeNode* root) {
    if(root == nullptr) return;
    PrintTree(root->left);
    cout << root->data;
    PrintTree(root->right);
}

void SwapChildren(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left != nullptr && root->right != nullptr) {
        swap(root->left, root->right);
    }
    SwapChildren(root->left);
    SwapChildren(root->right);
}

int GetTreeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(GetTreeHeight(root->left), GetTreeHeight(root->right));
}

int CountBalancedNode(TreeNode* root) {
    if (root == nullptr) return 0;
    int balanced_count = 0;
    int height_left = GetTreeHeight(root->left);
    int height_right = GetTreeHeight(root->right);

    if (height_left == height_right)
        balanced_count = 1;
    balanced_count += CountBalancedNode(root->left) + CountBalancedNode(root->right);
    return balanced_count;
}

int main() {
    //string test_sample = "ABD#E###CF##G##";
    string tree;
    cin >> tree;
    int i = 0;
    TreeNode* root = BuildTree(tree, i);
    SwapChildren(root);
    //cout << "The tree after swap: ";
    if (root != nullptr)
        PrintTree(root);
    else 
        cout << "NULL";
    //cout << "\nThe balanced node: "
    cout << endl << CountBalancedNode(root) << endl;
    
    return 0;
}
