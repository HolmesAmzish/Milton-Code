#include <iostream>
#include <utility>
using namespace std;

struct BinaryTreeNode {
    pair<int, int> element;
    BinaryTreeNode<int, int>* left_child;
    BinaryTreeNode<int, int>* right_child;

    BinaryTreeNode(pair<int, int>& the_element)
        : element(the_element), left_child(nullptr), right_child(nullptr) {}
};

class BinarySearchTree {
    pair<int, int> find(const int& the_key) {

    }
};