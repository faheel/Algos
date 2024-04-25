/*
    AVL Tree
    ------------------
    An AVL tree is a type of binary search tree that automatically keeps itself 
    balanced. In an AVL tree, the height difference between the left and right 
    subtrees of any node (known as the balance factor) is at most one. This balance
    is maintained through rotations, which are structural changes to the tree 
    that help in preserving its height properties. Operations like insertion, deletion,
    and search can be performed in O(log n) time, ensuring efficient data management.
*/

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int INF = INT_MAX;

struct Node {
    int value;
    int height;
    Node* left_child;
    Node* right_child;
};

class AVLTree {
private:
    Node* root;

    Node* get_node(int value);
    int height(Node* node);
    int balance_factor(Node* node);
    Node* right_rotate(Node* y);
    Node* left_rotate(Node* x);
    Node* insert_helper(Node* node, int value);
    Node* remove_helper(Node* node, int value);
    void inorder_traversal_helper(Node* node, vector<int>& values);

public:
    AVLTree();
    bool insert(int value);
    bool remove(int value);
    bool search(int value);
    vector<int> inorder_traversal();
};

Node* AVLTree::get_node(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->height = 1;
    newNode->left_child = newNode->right_child = nullptr;
    return newNode;
}

int AVLTree::height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::balance_factor(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left_child) - height(node->right_child);
}

Node* AVLTree::right_rotate(Node* y) {
    Node* x = y->left_child;
    Node* T2 = x->right_child;

    // Perform rotation
    x->right_child = y;
    y->left_child = T2;

    // Update heights
    y->height = 1 + max(height(y->left_child), height(y->right_child));
    x->height = 1 + max(height(x->left_child), height(x->right_child));

    return x;
}

Node* AVLTree::left_rotate(Node* x) {
    Node* y = x->right_child;
    Node* T2 = y->left_child;

    // Perform rotation
    y->left_child = x;
    x->right_child = T2;

    // Update heights
    x->height = 1 + max(height(x->left_child), height(x->right_child));
    y->height = 1 + max(height(y->left_child), height(y->right_child));

    return y;
}

Node* AVLTree::insert_helper(Node* node, int value) {
    if (node == nullptr) return get_node(value);

    if (value < node->value)
        node->left_child = insert_helper(node->left_child, value);
    else if (value > node->value)
        node->right_child = insert_helper(node->right_child, value);
    else
        return node; // Duplicate values not allowed

    // Update height of this node
    node->height = 1 + max(height(node->left_child), height(node->right_child));

    // Get the balance factor
    int balance = balance_factor(node);

    // Left Left Case
    if (balance > 1 && value < node->left_child->value)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right_child->value)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left_child->value) {
        node->left_child = left_rotate(node->left_child);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right_child->value) {
        node->right_child = right_rotate(node->right_child);
        return left_rotate(node);
    }

    return node;
}

Node* AVLTree::remove_helper(Node* node, int value) {
    if (node == nullptr) return node;

    if (value < node->value)
        node->left_child = remove_helper(node->left_child, value);
    else if (value > node->value)
        node->right_child = remove_helper(node->right_child, value);
    else {
        if (node->left_child == nullptr || node->right_child == nullptr) {
            Node* temp = node->left_child ? node->left_child : node->right_child;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = node->right_child;
            while (temp->left_child != nullptr) temp = temp->left_child;
            node->value = temp->value;
            node->right_child = remove_helper(node->right_child, temp->value);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + max(height(node->left_child), height(node->right_child));

    int balance = balance_factor(node);

    if (balance > 1 && balance_factor(node->left_child) >= 0)
        return right_rotate(node);

    if (balance > 1 && balance_factor(node->left_child) < 0) {
        node->left_child = left_rotate(node->left_child);
        return right_rotate(node);
    }

    if (balance < -1 && balance_factor(node->right_child) <= 0)
        return left_rotate(node);

    if (balance < -1 && balance_factor(node->right_child) > 0) {
        node->right_child = right_rotate(node->right_child);
        return left_rotate(node);
    }

    return node;
}

AVLTree::AVLTree() {
    root = nullptr;
}

bool AVLTree::insert(int value) {
    root = insert_helper(root, value);
    return true;
}

bool AVLTree::remove(int value) {
    if (!search(value)) return false;
    root = remove_helper(root, value);
    return true;
}

bool AVLTree::search(int value) {
    Node* current = root;
    while (current != nullptr) {
        if (value < current->value)
            current = current->left_child;
        else if (value > current->value)
            current = current->right_child;
        else
            return true; // Found
    }
    return false; // Not found
}

void AVLTree::inorder_traversal_helper(Node* node, vector<int>& values) {
    if (node == nullptr) return;
    inorder_traversal_helper(node->left_child, values);
    values.push_back(node->value);
    inorder_traversal_helper(node->right_child, values);
}

vector<int> AVLTree::inorder_traversal() {
    vector<int> values;
    inorder_traversal_helper(root, values);
    return values;
}

#endif