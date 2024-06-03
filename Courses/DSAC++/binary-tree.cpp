#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left_child;
    BinaryTreeNode* right_child;
    int height;

    BinaryTreeNode(int v) : value(v), left_child(nullptr), right_child(nullptr), height(1) {}
};

class BinaryTree {
private:
    BinaryTreeNode* root;

    int height(BinaryTreeNode* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(BinaryTreeNode* node) {
        return node ? height(node->left_child) - height(node->right_child) : 0;
    }

    void updateHeight(BinaryTreeNode* node) {
        if (node) {
            node->height = 1 + max(height(node->left_child), height(node->right_child));
        }
    }

    BinaryTreeNode* rotateRight(BinaryTreeNode* y) {
        BinaryTreeNode* x = y->left_child;
        BinaryTreeNode* T2 = x->right_child;

        // Perform rotation
        x->right_child = y;
        y->left_child = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    BinaryTreeNode* rotateLeft(BinaryTreeNode* x) {
        BinaryTreeNode* y = x->right_child;
        BinaryTreeNode* T2 = y->left_child;

        // Perform rotation
        y->left_child = x;
        x->right_child = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    BinaryTreeNode* insert(BinaryTreeNode* node, int value) {
        if (!node) return new BinaryTreeNode(value);

        if (value < node->value)
            node->left_child = insert(node->left_child, value);
        else if (value > node->value)
            node->right_child = insert(node->right_child, value);
        else
            return node; // Duplicate values are not allowed in this AVL tree

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left_child->value)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && value > node->right_child->value)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && value > node->left_child->value) {
            node->left_child = rotateLeft(node->left_child);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right_child->value) {
            node->right_child = rotateRight(node->right_child);
            return rotateLeft(node);
        }

        return node;
    }

    void preOrder(BinaryTreeNode* node) {
        if (node) {
            cout << node->value << " ";
            preOrder(node->left_child);
            preOrder(node->right_child);
        }
    }

    void inOrder(BinaryTreeNode* node) {
        if (node) {
            inOrder(node->left_child);
            cout << node->value << " ";
            inOrder(node->right_child);
        }
    }

    void postOrder(BinaryTreeNode* node) {
        if (node) {
            postOrder(node->left_child);
            postOrder(node->right_child);
            cout << node->value << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTreeNode* buildTree(vector<int> sequence) {
        for (int value : sequence) {
            root = insert(root, value);
        }
        return root;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    vector<int> sequence;
    int input;
    while (cin >> input && input != -1) {
        sequence.push_back(input);
    }

    tree.buildTree(sequence);

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    return 0;
}
