/*
 * File:        preorder-search.cpp
 * Date:        2024.04.21
 * Author:      Nulla
 * Description: Search for a node
 *              Print the children tree of the node by preorder 
 */

#include <iostream>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(const string& tree, int& index) {
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

void PrintTreeByPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data;
    PrintTreeByPreorder(root->left);
    PrintTreeByPreorder(root->right);

}

TreeNode* FindNode(TreeNode* root, const char& key) {
    if (root == nullptr) return nullptr;
    if (root->data == key) {
        return root;
    } else {
        TreeNode* left_result = FindNode(root->left, key);
        if (left_result != nullptr) return left_result;
        return FindNode(root->right, key);
    }
}

int main(void) {
    //string test_sample = "AB#C##DE#F###";
    //char test_key = 'D';
    string tree;
    char key;
    cin >> tree >> key;
    int i = 0;
    
    TreeNode* root = BuildTree(tree, i);
    TreeNode* key_node = FindNode(root, key);
    if (key_node == nullptr) {
        cout << "NONE" << endl;
    } else {
        if (key_node->left != nullptr || key_node->right != nullptr) {
            PrintTreeByPreorder(key_node->left);
            PrintTreeByPreorder(key_node->right);
        } else {
            cout << "NULL" << endl;
        }
    }

    return 0;
}
