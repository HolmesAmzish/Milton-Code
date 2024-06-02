#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left_child;
    BinaryTreeNode* right_child;

    BinaryTreeNode(int v) : value(v), left_child(nullptr), right_child(nullptr) {}
};

class BinaryTree {
    private:
    BinaryTreeNode* root;
    int tree_size;

    public:
    BinaryTree() : tree_size(0), root(nullptr) {}
    void preOrder() {

    }

    void midOrder() {

    }

    void postOrder() {
        
    }
};

int main() {

}