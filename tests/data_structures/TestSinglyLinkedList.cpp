#include "SinglyLinkedList.h"
#include "catch.hpp"

SCENARIO("A Singly Linked List can have items added and removed from it", "[SingleLinkedList]")
{
    GIVEN("A empty Singly Linked List") {
        SinglyLinkedList<int> list;

        REQUIRE(list.getSize() == 0);

        WHEN("Items are added") {
            list.insert(0);
            list.insert(1);
            list.insert(2);
            THEN("The size increases") {
                REQUIRE(list.getSize() == 3);
            }
        }

        WHEN("Items are removed") {
            list.remove(1);
            list.remove(1);
            list.remove(2);
            THEN("The list remains empty") {
                REQUIRE(list.getSize() == 0);
            }
        }
    }

    GIVEN("A Singly Linked List with one element") {
        SinglyLinkedList<int> list;
        list.insert(5);
        REQUIRE(list.getSize() == 1);

        WHEN("The item is removed") {
            list.remove(5);
            THEN("The list is empty") {
                REQUIRE(list.getSize() == 0);
            }
        }

        WHEN("A different item is quieried to be removed") {
            list.remove(3);
            THEN("The list remains the same size") {
                REQUIRE(list.getSize() == 1);
            }
        }
    }

    GIVEN("A Singly Linked List with two elements") {
        SinglyLinkedList<int> list;
        list.insert(7);
        list.insert(11);
        REQUIRE(list.getSize() == 2);

        WHEN("The head is removed") {
            list.remove(7);
            THEN("The list has the remaining element") {
                REQUIRE(list.getSize() == 1);
                REQUIRE(list.find(11) == 11);
            }
        }

        WHEN("The tail is removed") {
            list.remove(11);
            THEN("The list has the remaining element") {
                REQUIRE(list.getSize() == 1);
                REQUIRE(list.find(7) == 7);
            }
        }
    }

    GIVEN( "A Singly Linked List with three elements" ) {
        SinglyLinkedList<int> list;
        list.insert(7);
        list.insert(8);
        list.insert(9);
        REQUIRE(list.getSize() == 3);

        WHEN( "The head is removed" ) {
            list.remove(7);
            THEN( "The list has the remaining elements" ) {
                REQUIRE(list.getSize() == 2);
                REQUIRE(list.find(8) == 8);
                REQUIRE(list.find(9) == 9);
            }
        }

        WHEN( "The tail is removed" ) {
            list.remove(9);
            THEN("The list has the remaining elements") {
                REQUIRE(list.getSize() == 2);
                REQUIRE(list.find(7) == 7);
                REQUIRE(list.find(8) == 8);
            }
        }

        WHEN( "The middle is removed" ) {
            list.remove(8);
            THEN( "The list has the remaining elements" ) {
                REQUIRE(list.getSize() == 2);
                REQUIRE(list.find(7) == 7);
                REQUIRE(list.find(9) == 9);
            }
        }
    }
};
