/*
 * Program: binary-search-tree.cpp
 * Date: 2024.06.01
 * Author: Nulla
 * Description: Build a binary search tree by a sequence of number
 *              Print the tree by using parentheses
 */

#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left_child, *right_child;

    BinaryTreeNode(int v) {
        value = v;
        left_child = right_child = nullptr;
    }
};

class BinarySearchTree {
    private:
    BinaryTreeNode* root;
    int tree_size;

    public:
    BinarySearchTree() {
        root = nullptr;
        tree_size = 0;
    }

    BinaryTreeNode* insertNode(int value) {
        // Create a new node
        BinaryTreeNode* new_node = new BinaryTreeNode(value);

        // Set the new node as root if the tree is empty
        if (root == nullptr) {
            root = new_node;
            tree_size++;
            return;
        }

        // Find the insert position
        BinaryTreeNode *pointer = root,
                       *parent = nullptr;
        while (pointer != nullptr) {
            parent = pointer;
            if (value < pointer->value)
                pointer = pointer->left_child;
            else
                pointer = pointer->right_child;
        }

        // Connect the new node
        if (value < parent->value)
            parent->left_child = new_node;
        else
            parent->right_child = new_node;
        tree_size++;
    }

    BinaryTreeNode* buildTree(vector<int> sequence) {
        for (int value : sequence)
            insertNode(value);
    }

    void printTree(BinaryTreeNode* root) {
        if (root != nullptr) {
            cout << root;
            if (root->left_child != nullptr || root->right_child != nullptr) {
                cout << '(';
                printTree(root->left_child);
                cout << ',';
                printTree(root->right_child);
                cout << ')';
            }
        } else {
            return;
        }
    }
};

int main() {
    vector<int> sequence;
    int input;
    while (cin >> input && input != -1)
        sequence.push_back(input);
    BinarySearchTree tree;
    tree.buildTree(sequence);
    tree.printTree();
    
    return 0;
}