#include "../../include/catch.hpp"
#include "../../src/BinarySearchTree.h"

#include <vector>
SCENARIO("A BST can have its size queried", "[BST]") {
    
    GIVEN("A empty BST") {

        BinarySearchTree<int> aBST;
        WHEN("The size is queried") {
            THEN("It is 0") {
                REQUIRE(aBST.getSize() == 0);
            }
        }

        AND_WHEN("Elements are added") {
            aBST.insert(10);
            aBST.insert(9);
            aBST.insert(11);
            THEN("The size is the amount of items added") {
                REQUIRE(aBST.getSize() == 3);
            }
        }
    }
}

SCENARIO("A BST can have its elements queried", "[BST]") {

    GIVEN("A empty BST") {

        BinarySearchTree<int> aBST;
        WHEN("An element is queried") {
            THEN("It is a null pointer") {
                REQUIRE(aBST.find(3) == nullptr);
            }
        }

        AND_WHEN("Elements are added") {
            aBST.insert(10);
            aBST.insert(9);
            aBST.insert(11);

            THEN("The elements can be found") {
                REQUIRE(*aBST.find(9) == 9);
                REQUIRE(*aBST.find(10) == 10);
                REQUIRE(*aBST.find(11) == 11);
            }
            AND_THEN("Non-existing elements will return a null pointer") {
                REQUIRE(aBST.find(3) == nullptr);
                REQUIRE(aBST.find(7) == nullptr);
                REQUIRE(aBST.find(15) == nullptr);
            }
        }
    }
}

SCENARIO("A BST can have its elements removed", "[BST]") {
    
    GIVEN("A empty BST") {

        BinarySearchTree<int> aBST;
        WHEN("An element is attempted to be removed") {
            THEN("Nothing happens") {
                REQUIRE_NOTHROW(aBST.remove(10));
            }
        }
    }
    GIVEN("A BST with just a root") {

        BinarySearchTree<int> aBST;
        aBST.insert(5);

        REQUIRE(*aBST.find(5) == 5);

        WHEN("An element is removed") {
            aBST.remove(5);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(5) == nullptr);
            }
            AND_THEN("THe size shrinks") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
    }
    GIVEN("A BST with a root and a left leaf") {

        BinarySearchTree<int> aBST;
        const int root = 5;
        const int left = 4;
        aBST.insert(root);
        aBST.insert(left);

        REQUIRE(*aBST.find(root) == root);
        REQUIRE(*aBST.find(left) == left);

        WHEN("The root is removed") {
            aBST.remove(root);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
            }
            AND_THEN("The left leaf can be found") {
                REQUIRE(*aBST.find(left) == left);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The left leaf is removed") {
            aBST.remove(left);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(left) == nullptr);
            }
            AND_THEN("The root can be found") {
                REQUIRE(*aBST.find(root) == root);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The root is removed followed by the left") {
            aBST.remove(root);
            aBST.remove(left);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(left) == nullptr);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
        AND_WHEN("The left is removed followed by the root") {
            aBST.remove(left);
            aBST.remove(root);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(left) == nullptr);
                REQUIRE(aBST.find(root) == nullptr);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
    }
    GIVEN("A BST with a root and a right leaf") {

        BinarySearchTree<int> aBST;
        const int root = 5;
        const int right = 6;
        aBST.insert(root);
        aBST.insert(right);

        REQUIRE(*aBST.find(root) == root);
        REQUIRE(*aBST.find(right) == right);

        WHEN("The root is removed") {
            aBST.remove(root);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
            }
            AND_THEN("The right leaf can be found") {
                REQUIRE(*aBST.find(right) == right);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The right leaf is removed") {
            aBST.remove(right);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The root can be found") {
                REQUIRE(*aBST.find(root) == root);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The root is removed followed by the right") {
            aBST.remove(root);
            aBST.remove(right);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
        AND_WHEN("The right is removed followed by the root") {
            aBST.remove(right);
            aBST.remove(root);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(right) == nullptr);
                REQUIRE(aBST.find(root) == nullptr);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
    }
    GIVEN("A BST with a root, a left leaf and a right leaf") {

        BinarySearchTree<int> aBST;
        const int left = 4;
        const int root = 5;
        const int right = 6;
        aBST.insert(root);
        aBST.insert(left);
        aBST.insert(right);

        REQUIRE(*aBST.find(root) == root);
        REQUIRE(*aBST.find(left) == left);
        REQUIRE(*aBST.find(right) == right);

        WHEN("The root is removed") {
            aBST.remove(root);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
            }
            AND_THEN("The two leaves can be found") {
                REQUIRE(*aBST.find(left) == left);
                REQUIRE(*aBST.find(right) == right);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 2);
            }
        }
        AND_WHEN("The right leaf is removed") {
            aBST.remove(right);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The root and left leaf can be found") {
                REQUIRE(*aBST.find(root) == root);
                REQUIRE(*aBST.find(left) == left);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 2);
            }
        }
        AND_WHEN("The left leaf is removed") {
            aBST.remove(left);
            THEN("It can no longer be found") {
                REQUIRE(aBST.find(left) == nullptr);
            }
            AND_THEN("The root and right leaf can be found") {
                REQUIRE(*aBST.find(root) == root);
                REQUIRE(*aBST.find(right) == right);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 2);
            }
        }
        AND_WHEN("The root is removed followed by the right") {
            aBST.remove(root);
            aBST.remove(right);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The left leaf can be found") {
                REQUIRE(*aBST.find(left) == left);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The root is removed followed by the left") {
            aBST.remove(root);
            aBST.remove(left);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(left) == nullptr);
            }
            AND_THEN("The right leaf can be found") {
                REQUIRE(*aBST.find(right) == right);
            }
            AND_THEN("The size shrinks") {
                REQUIRE(aBST.getSize() == 1);
            }
        }
        AND_WHEN("The elements are removed pre-order") {
            aBST.remove(left);
            aBST.remove(root);
            aBST.remove(right);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(left) == nullptr);
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The size is empty") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
        AND_WHEN("The elements are removed in-order") {
            aBST.remove(root);
            aBST.remove(left);
            aBST.remove(right);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(left) == nullptr);
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The size is empty") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
        AND_WHEN("The elements are removed post-order") {
            aBST.remove(right);
            aBST.remove(left);
            aBST.remove(root);
            THEN("They can no longer be found") {
                REQUIRE(aBST.find(root) == nullptr);
                REQUIRE(aBST.find(left) == nullptr);
                REQUIRE(aBST.find(right) == nullptr);
            }
            AND_THEN("The size is empty") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
    }
}

SCENARIO("A larger BST can have its elements removed", "[BST]") {
    
    GIVEN("A BST with some elements") {
        BinarySearchTree<int> aBST;
        //          20
        //      /        \
        //     10         30
        //   /   \       /  \
        //  5     15   25    35
        //   \   /    /       \
        //    6 13   22        37
        int values[] = { 20, 10, 30, 5, 15, 25, 35, 6, 13, 22, 37 };
        int badValues[] = { 1, 2, 3, 4, 7, 8, 9, 11, 12, 14, 16, 21, 23, 24, 26, 31, 34, 36, 38 };
        for (int value : values) {
            aBST.insert(value);
        }
        for (int value : values) {
            REQUIRE(*aBST.find(value) == value);
        }
        for (int badValue : badValues) {
            REQUIRE(aBST.find(badValue) == nullptr);
        }

        for (int i = 0; i < 11; ++i) {
            WHEN("An element is removed") {
                aBST.remove(values[i]);

                // Looks like there is a bug with using multiple THEN/AND_THEN statements inside a for loop in Catch.
                // For now will just add all REQUIRE's here.
                THEN("The element cannot be found, the rest can, and the size shrinks") {
                    for (int j = 0; j < 11; ++j) {
                        if (j == i) {
                            REQUIRE(aBST.find(values[i]) == nullptr);
                        }
                        else {
                            REQUIRE(*aBST.find(values[j]) == values[j]);
                        }
                    }
                    REQUIRE(aBST.getSize() == 10);
                    for (int badValue : badValues) {
                        REQUIRE(aBST.find(badValue) == nullptr);
                    }
                }
            }
        }
        AND_WHEN("All the elements are removed") {
            for (int value : values) {
                aBST.remove(value);
            }
            THEN("All the elements cannot be found") {
                for (int value : values) {
                    REQUIRE(aBST.find(value) == nullptr);
                }
            }
            AND_THEN("All the bad values cannot be found") {
                for (int badValue : badValues) {
                    REQUIRE(aBST.find(badValue) == nullptr);
                }
            }
            AND_THEN("The size is 0") {
                REQUIRE(aBST.getSize() == 0);
            }
        }
    }
}