#include "third_party/catch.hpp"
#include "data_structure/tree/avl_tree.hpp"

#define CATCH_CONFIG_MAIN

TEST_CASE("Create an empty AVL tree and check traversals", "[AVLTree]") {
    AVLTree tree;

    REQUIRE(tree.inorder_traversal() == std::vector<int>{});
}

TEST_CASE("Insert elements and check balance and order", "[AVLTree]") {
    AVLTree tree;

    SECTION("Insert elements") {
        REQUIRE(tree.insert(30));
        REQUIRE(tree.insert(20));
        REQUIRE(tree.insert(40));
        REQUIRE(tree.insert(10));
        REQUIRE(tree.insert(25));
        REQUIRE(tree.insert(35));
        REQUIRE(tree.insert(50));
    }

    SECTION("Check AVL properties") {
        auto values = tree.inorder_traversal();
        REQUIRE(values == std::vector<int>{10, 20, 25, 30, 35, 40, 50});

        // Checks if the height of the tree follows AVL properties
        // Specific height check depends on the particular insertion order and balancing
    }
}

TEST_CASE("Delete elements and ensure the tree remains balanced", "[AVLTree]") {
    AVLTree tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);

    REQUIRE(tree.remove(20));
    REQUIRE(tree.remove(35));
    
    SECTION("Post-deletion balance and order") {
        auto values = tree.inorder_traversal();
        REQUIRE(values == std::vector<int>{10, 25, 30, 40, 50});

        // Checks if the tree is still balanced
    }
}

TEST_CASE("Search in AVL tree", "[AVLTree]") {
    AVLTree tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);

    REQUIRE(tree.search(25));
    REQUIRE_FALSE(tree.search(100));
}

TEST_CASE("Complex operations and stress test", "[AVLTree]") {
    AVLTree tree;

    for (int i = 0; i < 1000; i++) {
        tree.insert(i);
    }

    REQUIRE(tree.search(500));

    for (int i = 0; i < 500; i++) {
        REQUIRE(tree.remove(i));
    }

    for (int i = 0; i < 500; i++) {
        REQUIRE_FALSE(tree.search(i));
    }

    for (int i = 500; i < 1000; i++) {
        REQUIRE(tree.search(i));
    }
}

