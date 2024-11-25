#include "third_party/catch.hpp"
#include "data_structure/tree/avl_tree.hpp"


TEST_CASE("create and test an empty AVL Tree", "[avl-tree]") {
    AVLTree<int> avl_tree;
    vector<int> empty_vector = {};

    REQUIRE(avl_tree.empty());
    REQUIRE(avl_tree.remove(1) == false);
    REQUIRE(avl_tree.inorder() == empty_vector);
    REQUIRE(avl_tree.postorder() == empty_vector);
    REQUIRE(avl_tree.preorder() == empty_vector);
    REQUIRE(avl_tree.levelorder() == empty_vector);
    REQUIRE(avl_tree.sorted(true) == empty_vector);
    REQUIRE(avl_tree.sorted(false) == empty_vector);
}


TEST_CASE("Add and remove values", "[avl-tree]") {
    AVLTree<int> avl_tree;
    // some distinct values
    vector<int> test_vector = {37, 23, 41, -20, 11, 4, 29, 6, 19, -7, 36, -11, 21, 33, 15, 28, 30, 35, 27, 48, -13};
    for (int i : test_vector) {
        avl_tree.insert(i);
    }

    // confirm true positives
    for (int i : test_vector) {
        REQUIRE(avl_tree.search(i));
    }
    // check for false positives
    REQUIRE(avl_tree.search(1000) == false);
    REQUIRE(avl_tree.search(1001) == false);
    REQUIRE(avl_tree.search(1002) == false);
    REQUIRE(avl_tree.search(1003) == false);


    // remove some values that existed in the tree
    REQUIRE(avl_tree.remove(23));
    REQUIRE(avl_tree.remove(41));
    REQUIRE(avl_tree.remove(-20));
    REQUIRE(avl_tree.remove(11));
    REQUIRE(avl_tree.remove(4));

    // check that the previous values are indeed removed from the tree
    REQUIRE(avl_tree.search(23) == false);
    REQUIRE(avl_tree.search(41) == false);
    REQUIRE(avl_tree.search(-20) == false);
    REQUIRE(avl_tree.search(11) == false);
    REQUIRE(avl_tree.search(4) == false);

    // check that values that were not removed are still in the tree
    REQUIRE(avl_tree.search(-13));
    REQUIRE(avl_tree.search(48));
    REQUIRE(avl_tree.search(27));
    REQUIRE(avl_tree.search(35));
}


TEST_CASE("Traversals", "[avl-tree]") {
    AVLTree<int> avl_tree;
    // some distinct values
    vector<int> test_vector = {37, 23, 41, -20, 11, 4, 29, 6, 19, -7, 36, -11, 21, 33, 15, 28, 30, 35, 27, 48, -13};
    for (int i : test_vector) {
        avl_tree.insert(i);
    }
    REQUIRE(avl_tree.inorder() ==
        vector<int>{-20, -13, -11, -7, 4, 6, 11, 15, 19, 21, 23, 27, 28, 29, 30, 33, 35, 36, 37, 41, 48});
    REQUIRE(avl_tree.preorder() ==
        vector<int>{11, -11, -20, -13, 4, -7, 6, 29, 21, 19, 15, 27, 23, 28, 36, 33, 30, 35, 41, 37, 48});
    REQUIRE(avl_tree.postorder() ==
        vector<int>{-13, -20, -7, 6, 4, -11, 15, 19, 23, 28, 27, 21, 30, 35, 33, 37, 48, 41, 36, 29, 11});
    REQUIRE(avl_tree.levelorder() ==
        vector<int>{11, -11, 29, -20, 4, 21, 36, -13, -7, 6, 19, 27, 33, 41, 15, 23, 28, 30, 35, 37, 48});
}


TEST_CASE("Confirm tree has AVL structure", "[avl-tree]") {
    /* Test to confirm that the tree remains in AVL form after
     * insertions/deletions. To confirm that the tree is actually
     * in AVL form the levelorder traversal is being used as it
     * has the desired property that each AVL tree corresponds to
     * one and only one levelorder traversal and vice versa.
     */

    AVLTree<int> avl_tree;

    // some distinct values
    vector<int> test_vector = {37, 23, 41, -20, 11, 4, 29, 6, 19, -7, 36, -11, 21, 33, 15, 28, 30, 35, 27, 48, -13};
    for (int i : test_vector) {
        avl_tree.insert(i);
    }

    REQUIRE(avl_tree.levelorder() ==
        vector<int>{11, -11, 29, -20, 4, 21, 36, -13, -7, 6, 19, 27, 33, 41, 15, 23, 28, 30, 35, 37, 48});

    // remove some values and confirm again
    avl_tree.remove(-13);
    avl_tree.remove(4);
    avl_tree.remove(19);
    avl_tree.remove(11);

    REQUIRE(avl_tree.levelorder() ==
        vector<int>{15, -11, 29, -20, 6, 27, 36, -7, 21, 28, 33, 41, 23, 30, 35, 37, 48});
}


TEST_CASE("Test Min-Max", "[avl-tree]") {
    AVLTree<int> avl_tree;

    // some distinct values
    vector<int> test_vector = {37, 23, 41, -200, 11, 4, 29, 6, 19, -7, 36, -11, 21, 33, 15, 28, 30, 35, 27, 480, -13};
    for (int i : test_vector) {
        avl_tree.insert(i);
    }
    REQUIRE(avl_tree.max() == 480);
    REQUIRE(avl_tree.min() == -200);
}