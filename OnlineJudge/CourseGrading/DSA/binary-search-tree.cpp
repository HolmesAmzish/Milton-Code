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
    public:
    BinaryTreeNode* root;
    int tree_size;

    BinarySearchTree() {
        root = nullptr;
        tree_size = 0;
    }

    void insertNode(int value) {
        // Create a new node
        BinaryTreeNode* new_node = new BinaryTreeNode(value);

        // Set the new node as root if the tree is empty
        if (root == nullptr) {
            root = new_node;
            tree_size++;
            printTree(root);
            cout << endl;
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
        else if (value > parent->value)
            parent->right_child = new_node;
        tree_size++;
        
        // Print the tree while construction
        printTree(root);
        cout << endl;
    }

    // Build the tree in a loop and print the process
    BinaryTreeNode* buildTree(vector<int> sequence) {
        for (int value : sequence)
            insertNode(value);
        return root;
    }

    void printTree(BinaryTreeNode* root) {
        if (root != nullptr) {
            cout << root->value;
            if (root->left_child != nullptr || root->right_child != nullptr) {
                cout << '(';
                printTree(root->left_child);
                cout << ',';
                printTree(root->right_child);
                cout << ')';
            }
        }
    }

    void find(int key) {
        while (root != nullptr) {
            cout << root->value << ' ';
            if (key == root->value)
                break;
            
            if(key < root->value)
                root = root->left_child;
            else if (key > root->value)
                root = root->right_child;
        }
    }
};

int main() {
    vector<int> sequence;
    int input, key;
    while (cin >> input && input != -1)
        sequence.push_back(input);
    cin >> key;
    BinarySearchTree tree;
    BinaryTreeNode* root = tree.buildTree(sequence);
    //tree.printTree(root);
    tree.find(key);
    
    return 0;
}