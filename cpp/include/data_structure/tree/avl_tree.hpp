/*
    AVL Tree
    --------
    An AVL Tree is a type of self-balancing binary search tree where the
    difference in heights between the right and left subtrees of any node
    (called the balance factor) is either -1, 0, or 1. If the after an
    insertion or deletion the balance factor of a node becomes 2 or -2
    the AVL tree maintains balance by performing appropriate rotations
    (left, right, left-right, and right-left). This balancing ensures that
    the tree’s height remains logarithmic relative to the number of nodes,
    guaranteeing efficient performance for search, insertion, and deletion
    operations—each having O(log(n)) complexity time, where n is the
    number of values in the tree.
 */

#ifndef PROALGOS_CPP_AVL_TREE_HPP
#define PROALGOS_CPP_AVL_TREE_HPP

using namespace std;

#include <stack>
#include <queue>
#include <vector>
#include <algorithm>


template <class  T> class AVLNode{
    public:
    T value;
    // balance_factor = height(right_child) - height(left_child).
    // char data type is used because it will only take values in the range [-2, 2]
    char balance_factor;
    AVLNode* right_child;
    AVLNode* left_child;

    explicit AVLNode(const T value){
        this->value = value;
        // by default when a new node is created its left and right
        // children are NULL so the balance factor is 0
        balance_factor = 0;
        left_child = right_child = nullptr;
    }

};

template <class  T> class AVLTree{
    AVLNode<T>* root;

    static void update_and_balance(stack<AVLNode<T>**> &visit_order, AVLNode<T>** current_node);
    static AVLNode<T>* left_rotation(AVLNode<T>*);
    static AVLNode<T>* right_rotation(AVLNode<T>*);
    static AVLNode<T>* left_right_rotation(AVLNode<T>*);
    static AVLNode<T>* right_left_rotation(AVLNode<T>*);
    static void balance_tree(AVLNode<T>* &node);

public:
    AVLTree();
    [[nodiscard]] bool empty() const;
    bool insert(T);
    bool remove(T);
    [[nodiscard]] bool search(T) const;
    [[nodiscard]] T min() const;
    [[nodiscard]] T max() const;
    [[nodiscard]] vector<T> inorder() const;
    [[nodiscard]] vector<T> preorder() const;
    [[nodiscard]] vector<T> postorder() const;
    [[nodiscard]] vector<T> levelorder() const;
    [[nodiscard]] vector<T> sorted(bool) const;
};



template <class  T>
AVLNode<T>* AVLTree<T> :: left_rotation(AVLNode<T>* unbalanced_node) {
    AVLNode<T>* new_root = unbalanced_node->right_child;
    unbalanced_node->right_child = new_root->left_child;
    new_root->left_child = unbalanced_node;
    if (new_root->balance_factor == 0) {
        new_root->balance_factor = -1;
        unbalanced_node->balance_factor = 1;
    } else{
        new_root->balance_factor = unbalanced_node->balance_factor = 0;
    }
    return new_root;
}

template <class T>
AVLNode<T>* AVLTree<T> :: right_rotation(AVLNode<T>* unbalanced_node) {
    AVLNode<T>* new_root = unbalanced_node->left_child;
    unbalanced_node->left_child = new_root->right_child;
    new_root->right_child = unbalanced_node;
    if (new_root->balance_factor == 0) {
        new_root->balance_factor = 1;
        unbalanced_node->balance_factor = -1;
    } else{
        new_root->balance_factor = unbalanced_node->balance_factor = 0;
    }
    return new_root;
}


template <class T>
AVLNode<T>* AVLTree<T> :: right_left_rotation(AVLNode<T>* unbalanced_node) {
    AVLNode<T> *temp_node = unbalanced_node->right_child;
    // will become the new root of the subtree after the rotations
    AVLNode<T> *new_root = temp_node->left_child;

    unbalanced_node->right_child = new_root->left_child;

    temp_node->left_child = new_root->right_child;
    new_root->left_child = unbalanced_node;
    new_root->right_child = temp_node;

    if (new_root->balance_factor == 0){
        unbalanced_node->balance_factor = temp_node->balance_factor = 0;
    }
    else if (new_root->balance_factor == 1){
        unbalanced_node->balance_factor = -1;
        temp_node->balance_factor = 0;
    } else{ // balance factor of new_root was -1
        unbalanced_node->balance_factor = 0;
        temp_node->balance_factor = 1;
    }
    // new_root is now the new root of the balanced subtree so its balance factor is 0
    new_root->balance_factor = 0;
    return new_root;

}


template <class T>
AVLNode<T>* AVLTree<T> :: left_right_rotation(AVLNode<T>* unbalanced_node) {
    AVLNode<T>* temp_node = unbalanced_node->left_child;
    // will become the new root after the rotations
    AVLNode<T>* new_root = temp_node->right_child;

    unbalanced_node->left_child = new_root->right_child;

    temp_node->right_child = new_root->left_child;
    new_root->right_child = unbalanced_node;
    new_root->left_child = temp_node;

    if (new_root->balance_factor == 0){
        unbalanced_node->balance_factor = temp_node->balance_factor = 0;
    }
    else if (new_root->balance_factor == -1){
        unbalanced_node->balance_factor = 1;
        temp_node->balance_factor = 0;
    } else{ // balance factor of new_root was -1
        unbalanced_node->balance_factor = 0;
        temp_node->balance_factor = -1;
    }
    // new_root is now the root of the balanced subtree so its balance factor is 0
    new_root->balance_factor = 0;
    return new_root;
}

template <class T> AVLTree<T>::AVLTree() {root = nullptr;}

// Helper function that checks if a node is unbalanced and executes the appropriate
// rotations (left, right, left-right, or right-left) if needed.
template <class T>
void AVLTree<T>::balance_tree(AVLNode<T>* &node) {

    if (node->balance_factor == -2) { // tree is unbalanced and left heavy
        if (node->left_child->balance_factor == 1) // left subtree is right heavy
            node = left_right_rotation(node);
        else {    // left subtree is left heavy or balanced
            node = right_rotation(node);
        }
    }
    else if (node->balance_factor == 2){    // tree is unbalanced and right heavy
        if (node->right_child->balance_factor == -1) // right subtree is left heavy
            node = right_left_rotation(node);
        else    // left subtree is right heavy or balanced
            node = left_rotation(node);
    }
}

template <class T> bool AVLTree<T>::empty() const {return root == nullptr;}


/*
    search
    ------
    The search operation in an AVL tree is identical to that of a Binary Search Tree.
    Starting from the root, it follows the binary search process: if the target value
    is less than the current node it searches in the left subtree; if greater it searches
    in the right subtree. The above process continues until the input value is found
    (returns true) or until the current node becomes NULL meaning that the input value
    doesn't exist in the tree(returns false). The self-balancing nature of the AVL tree
    ensures that the search time complexity remains O(log(n)) since the height of the
    tree is kept logarithmic.

    Time complexity
    ---------------
    O(log(n)), where n is the number of nodes in the tree

    Space complexity
    ----------------
    O(1)
*/

template <class T>
bool AVLTree<T>::search(const T value) const{
    const AVLNode<T>* current_node = root;
    while (current_node != nullptr){
        if (value < current_node->value)
            current_node = current_node->left_child;
        else if (value > current_node->value)
            current_node = current_node->right_child;
        else return true;
    }
    return false;
}

/*
    insert
    ------
    If the tree is empty then the target value gets inserted in the root node.
    Else, starting from the root it uses the binary tree property to follow the
    appropriate subtree until it finds a node that is either NULL node or has
    with the same value as the target value. In the first case it inserts the
    target value into the NULL node and returns "true". In the second case it
    returns "false". After each insertion, the balance factor of the ancestor
    nodes might need to be updated and the tree can become unbalanced. To
    update the balance factors and re-balance the tree the update_and_balance
    function is called.

    Time complexity
    ---------------
    O(log(n)), where n is the number of nodes in the tree

    Space complexity
    ----------------
    O(log(n))
*/
template <class T>
bool AVLTree<T>::insert(const T value) {
    if (empty()){
        root = new AVLNode<T>(value);
        return true;
    }

    AVLNode<T>** current_node = &root;
    // stack to keep record of the parent addresses of the nodes we visit
    stack<AVLNode<T>**> visit_order;

    while (value != (*current_node)->value){
        if (value < (*current_node)->value) {
            if ((*current_node)->left_child == nullptr){
                (*current_node)->left_child = new AVLNode<T>(value);
                // left subtree grows by one so the balance factor of the current_node should be reduced by one
                --(*current_node)->balance_factor;
                update_and_balance(visit_order, current_node);
                return true;
            }
            visit_order.push(current_node);
            current_node = &( (*current_node)->left_child);
        } else {

            if ((*current_node)->right_child == nullptr){
                (*current_node)->right_child = new AVLNode<T>(value);
                // right subtree grows by one so the balance factor of the current_node should be increased by one
                ++(*current_node)->balance_factor;
                update_and_balance(visit_order, current_node);
                return true;
            }
            visit_order.push(current_node);
            current_node = &( (*current_node)->right_child);
        }
    }
    // the value already exists in the tree
    return false;
}

/*
    update_and_balance
    ------------------
    Helper function for the insert operation.

    Parameters:
        current_node: points to the parent of the newly added node.

        visit_order: stack that has stored the addresses of the current_node's
        ancestors all the way up to the root. It is used to backtrack the
        nodes visited by the insert function.

    The function starts backtracking the nodes visited by the insert function
    starting from current_node's parent. At each node, it updates its balance
    factor accordingly and balances it if needed. For the balancing the
    balance_tree function is being called. The backtracking stops if the
    current balance factor becomes 0 which means that the subtree is balanced.

 */
template <class T>
void AVLTree<T>::update_and_balance(stack<AVLNode<T>**> &visit_order, AVLNode<T>** current_node) {
    while (not visit_order.empty() and (*current_node)->balance_factor != 0) {
        AVLNode<T>** parent_node = visit_order.top();
        visit_order.pop();
        if (*current_node == (*parent_node)->right_child)
            ++(*parent_node)->balance_factor;
        else --(*parent_node)->balance_factor;
        balance_tree(*parent_node);
        current_node = parent_node;
    }
}


/*
    remove
    ------
    Function to remove a given value from the tree. The function works in
    three steps.

    1:  Locates the node which holds the value that has to be removed (current_node).
        If such node does not exist it returns "false".

    2:  Delete the given value from the tree. This step consists of two cases.

        A:  current_node has no right child which means that it is
            either 1: a leaf node or 2: its left child is a leaf node
            (otherwise the tree would be unbalanced). In case A1 current_node
            gets deleted (unless it is the root). In case A2 the value of
            the current_node's left child gets copied to the current_node and
            the child gets deleted. In both cases the parent node is updated
            accordingly.

        B:  current_node has two non-NULL children. Here the function
            first locates the inorder successor of the current_node and
            copies its value to it. Afterwards, the successor gets deleted
            and its parent node gets updated accordingly.

    3:  After the deletion of the successor is complete, it starts backtracking
        the nodes it visited (via the stack) updates their balance factors
        and re-balances them if needed. The backtracking stops if current
        balance factor becomes 1 or -1 because the subtree is already balanced
        (its balance factor must have been 0 before the deletion).

    Time complexity
    ---------------
    O(log(n)) where n is the number of nodes in the tree, because it will
    have to traverse to a leaf node of the tree. It does not matter where
    the node we want to delete is placed.

    Space complexity
    ----------------
    O(log(n)) because it has to store the ancestor nodes of the nodes
    being visited, and it always visits a leaf node.

*/

template <class T>
bool AVLTree<T>::remove(const T value) {
    AVLNode<T>** parent_node = nullptr;
    AVLNode<T>** current_node = &root;
    stack<AVLNode<T>**> visit_order;

    // find the node to be removed
    while (*current_node != nullptr and (*current_node)->value != value){
        parent_node = current_node;
        visit_order.push(parent_node);
        if (value < (*current_node)->value){
            current_node = &((*current_node)->left_child);
        } else
            current_node = &((*current_node)->right_child);
    }
    // value does not exist in the tree
    if (*current_node == nullptr)
        return false;

    // case A: right child is NULL so the left child is either 1: also NULL or 2: a leaf node
    // because the tree is in AVL form.
    if ((*current_node)->right_child == nullptr){
        // case A1:
        if ((*current_node)->left_child == nullptr){   // current node is a leaf node
            if (parent_node == nullptr){    // current node points to the root
                root = nullptr;
            } else { // update the parent node accordingly
                if (current_node == (&(*parent_node)->left_child)){
                    (*parent_node)->left_child = nullptr;
                    ++(*parent_node)->balance_factor;
                } else{
                    (*parent_node)->right_child = nullptr;
                    --(*parent_node)->balance_factor;
                }
                delete *current_node;
            }
        }
        else { // case A2:

            (*current_node)->value = (*current_node)->left_child->value;
            (*current_node)->balance_factor = 0;
            // current_node now becomes a leaf so its balance factor is 0
            delete (*current_node)->left_child;
            (*current_node)->left_child = nullptr;
            if (parent_node != nullptr){
                // if current_node has a parent update its balance factor as well
                if (current_node == (&(*parent_node)->left_child)){
                    ++(*parent_node)->balance_factor;
                } else{
                    --(*parent_node)->balance_factor;
                }
            }

        }
    }

    else {  // case B:
        // find the inorder successor of the current node,
        // copy its value to it and delete the successor.
        AVLNode<T>** successor = &( (*current_node)->right_child);
        visit_order.push(current_node);

        while ((*successor)->left_child != nullptr){
            visit_order.push(successor);
            successor = &( (*successor)->left_child);
        }
        (*current_node)->value = (*successor)->value;

        if (visit_order.top() == current_node) { // successor is the direct right child of the current node
            // right child gets deleted so the balance factor gets reduced by one.
            --(*visit_order.top())->balance_factor;
            (*visit_order.top())->right_child = (*successor)->right_child;
        } else {
            // successor is further down the right subtree of the current node
            // which means that it is its parents left child.

            // left child gets deleted so the balance factor gets increased by one
            ++(*visit_order.top())->balance_factor;
            if ((*successor)->right_child == nullptr){  // successor is a leaf node
                (*visit_order.top())->left_child = nullptr;
                delete *successor;
            }
            else { // successor has one right child which is a leaf node
                // copy the child values onto the successor node and delete the child node.
                (*successor)->balance_factor = 0;
                (*successor)->value = (*successor)->right_child->value;
                delete (*successor)->right_child;
                (*successor)->right_child = nullptr;
            }
        }
    }

    if (not visit_order.empty()) {
        current_node = visit_order.top();
        visit_order.pop();
        balance_tree(*current_node);
        while (not visit_order.empty() and (*current_node)->balance_factor != 1 and (*current_node)->balance_factor != -1){
            parent_node = visit_order.top();
            visit_order.pop();
            if (*current_node == (*parent_node)->left_child){
                ++(*parent_node)->balance_factor;
            } else --(*parent_node)->balance_factor;
            current_node = parent_node;
            balance_tree(*current_node);
        }
    }
    return true;
}



/*
    min
    ---
    Returns the minimum value stored in the tree. No checking is being done
    to see if the tree is empty to match the behaviour of the other traditional
    c++ data structures.

    Time complexity
    ---------------
    Worst case: O(log(n)), where n is the number of nodes in the tree

    Space complexity
    ----------------
    O(1)
 */

template <class T>
T AVLTree<T>::min() const{
    const AVLNode<T>* min_node = root;
    while (min_node->left_child != nullptr){
        min_node = min_node->left_child;
    }
    return min_node->value;

}
/*
    max
    ---
    Returns the maximum value stored in the tree. No checking is being done
    to see if the tree is empty to match the behaviour of the other traditional
    c++ data structures.

    Time complexity
    ---------------
    Worst case: O(log(n)), where n is the number of nodes in the tree

    Space complexity
    ----------------
    O(1)
 */


template <class T>
T AVLTree<T>::max() const {
    const AVLNode<T>* min_node = root;
    while (min_node->right_child != nullptr){
        min_node = min_node->right_child;
    }
    return min_node->value;
}

/*
    Traversals (inorder, preorder, postorder, levelorder)
    -----------------------------------------------------
    Iterative implementations of the most common tree traversals.

    1.Inorder Traversal (Left, Root, Right):
        Visit the left subtree first, then the root node, and finally the
        right subtree.

    2.Preorder Traversal (Root, Left, Right):
        Visit the root node first, then the left subtree, and finally the
        right subtree.
        This traversal is useful for creating a copy of the tree or evaluating expressions in expression trees.

    3.Postorder Traversal (Left, Right, Root):
        Visit the left subtree first, then the right subtree, and finally
        the root node.
        This traversal is helpful for deleting or freeing nodes
        in a tree structure as it visits all children before the parent.

    4.Level Order Traversal (or Breadth-First Traversal).
        Starting from the root node, it visits all nodes at depth 1
        (children of the root), then all nodes at depth 2, and so on.
        This traversal is implemented using a queue, where nodes are
        enqueued as they are visited to ensure each level is processed
        sequentially. The level order traversal is very useful for creating
        a visual representation the AVL tree structure as each sequence
        of values corresponds to one and only one AVL tree structure
        and vice versa.

    Time complexity
    ---------------
    O(n), where n is the number of nodes in the tree

    Space complexity
    ----------------
    O(n)
 */


template <class T>
vector<T> AVLTree<T>::inorder() const {
    vector<T> values;
    stack<AVLNode<T>*> traversal;
    AVLNode<T>* current = root;
    while (not traversal.empty() or current != nullptr) {
        if (current != nullptr) {
            traversal.push(current);
            current = current->left_child;
        } else {
            current = traversal.top();
            traversal.pop();
            values.push_back(current->value);
            current = current->right_child;
        }

    }
    return values;
}

template <class T>
vector<T> AVLTree<T>::preorder() const {
    vector<T> values;
    if (not empty()) {
        stack<AVLNode<T>*> traversal;
        traversal.push(root);
        while (not traversal.empty()) {
            const AVLNode<T>* current = traversal.top();
            traversal.pop();
            values.push_back(current->value);
            if (current->right_child != nullptr)
                traversal.push(current->right_child);
            if (current->left_child != nullptr)
                traversal.push(current->left_child);
        }
    }
    return values;
}

template <class T>
vector<T> AVLTree<T>::postorder() const {
    vector<T> values;
    if (not empty()) {
        stack<AVLNode<T>*> traversal;
        const AVLNode<T>* previous_node = nullptr;
        AVLNode<T>* current_node = root;
        while (not traversal.empty() or current_node != nullptr) {
            if (current_node != nullptr) {
                traversal.push(current_node);
                current_node = current_node->left_child;
            }
            else {
                // if right child exists and the previous node wasn't the parent
                if (traversal.top()->right_child != nullptr and  traversal.top()->right_child != previous_node) {
                    current_node = traversal.top()->right_child;
                }
                else {
                    values.push_back(traversal.top()->value);
                    previous_node = traversal.top();
                    traversal.pop();
                }
            }
        }
    }
    return values;
}

template <class T>
vector<T> AVLTree<T>::levelorder() const{
    vector<T> values;
    if (not empty()) {
        queue<AVLNode<T>*> queue;
        queue.push(root);
        while (not queue.empty()) {
            const AVLNode<T>* current = queue.front();
            queue.pop();
            if (current != nullptr) {
                values.push_back(current->value);
                if (current->left_child != nullptr)
                    queue.push(current->left_child);
                if (current->right_child != nullptr)
                    queue.push(current->right_child);
            }
        }
    }
    return values;
}

/*
    sorted
    ------
    Returns a vector containing the values of the tree sorted in ascending
    or descending order. The function makes use of the fact that an inorder
    traversal of a binary search tree always returns the values in ascending
    order.

    Time complexity:
    ----------------
    O(n), where n is the number of nodes in the tree

    Space complexity:
    -----------------
    O(n)

 */
template<class T>
vector<T> AVLTree<T>::sorted(const bool ascending) const {
    // by default the inorder traversal gives us the values in increasing order
    vector<T> values = inorder();
    if (not ascending) // if we want descending order just reverse the vector
        reverse(values.begin(), values.end());

    return values;
}



#endif //PROALGOS_CPP_AVL_TREE_HPP