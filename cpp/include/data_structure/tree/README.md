# Tree
Trees are a group of data structures that are named this way because of how they look when conceptually drawn or because of how the different elements connect to each other. Trees are used to solve a variety of different problems, such as storing data so that it quickly searched for later, allowing prefix sums to be calculated quickly, or to store data in a hierarchical structure.

### Contents

1. [Fenwick tree](#1-fenwick-tree)
2. [Binary search tree](#2-binary-search-tree)

---

## 1. Fenwick tree
A fenwick tree offers a more equitable tradeoff between updating an array of prefix sums and calculating prefix sums. Both the update operation and the calculate operation are implemented with the time complexity of O(log n). That can be compared to the naive implementation where the calculate operation is O(1), and the update operation is O(n).

### Usage

```c++
vector<int> original_array{10, 3, 15, 12, 5};

FenwickTree tree(original_array);

// calculate the sum from index 0 -> 2
tree.calculate_prefix_sum(2)

// add 3 to the value located at index = 2
tree.update_tree(3, 2);

// add -3 to the value located at index = 2
tree.update_tree(-3, 2);
```

### Complexity
Operation   | Time         | Space
----------- | ------------ |-------------------
_Update_    | _O(log N)_   | _O(N)_
_Calculate_ | _O(log N)_   | _O(N)_

Where N is the number of elements in the original array.

## 2. Binary search tree
A binary tree where the value of each node to the right of the current node is larger than or equal to the value of the current node, and the value of the node to the left is less than or equal to the the value of the current node. Storing data using a binary search tree allows a good compromise to be made between insertion speed and search speed.

### Usage
```c++
BinarySearchTree tree;

// inserting values into the tree
tree.insert(1);
tree.insert(0);
tree.insert(-1);
tree.insert(5);
tree.insert(2);
tree.insert(3);
tree.insert(4);
tree.insert(6);

// to delete an element
tree.remove(4);

// to search for an element
tree.search(2)

// for inorder traversal using the recursive method
// Output will be this array:
tree.traversal_inorder_recursive();

// for inorder traversal using the recursive method
// Output will be this array:
tree.traversal_inorder_iterative();

// the rest of the traversals follow the same method
// replacing inorder with preorder or postorder
```

### Complexity
Operation                | Time                             | Space
------------------------ | -------------------------------- |-------------------
_Insert_                 | Average: O(log N), Worst: O(N)   | _O(1)_
_Remove_                 | Average: O(log N), Worst: O(N)   | _O(1)_
_Search_                 | Average: O(log N), Worst: O(N)   | _O(1)_
_Inorder Traversal_      | _O(N)_                           | _O(N)_
_Preorder Traversal_     | _O(N)_                           | _O(N)_
_Postorder Traversal_    | _O(N)_                           | _O(N)_

Where N is the number of elements in the tree.
