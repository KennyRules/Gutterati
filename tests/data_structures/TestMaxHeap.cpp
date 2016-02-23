#include "catch.hpp"
#include "MaxHeap.h"

SCENARIO("A MaxHeap can have elements added", "[MaxHeap]") {

    GIVEN("A empty MaxHeap") {
        MaxHeap<int> aMaxHeap;

        WHEN("The size is queried") {

            THEN("The size is 0") {
                REQUIRE(aMaxHeap.getSize() == 0);
            }
            AND_THEN("The MaxHeap reports it is empty") {
                REQUIRE(aMaxHeap.isEmpty() == true);
            }
        }
        AND_WHEN("Elements are added") {
            aMaxHeap.insert(1);
            aMaxHeap.insert(2);
            aMaxHeap.insert(3);

            THEN("The size increases") {
                REQUIRE(aMaxHeap.getSize() == 3);
            }
            AND_THEN("The MaxHeap reports it is not empty") {
                REQUIRE(aMaxHeap.isEmpty() == false);
            }
        }
    }
}

SCENARIO("A MaxHeap can have the maximum element extracted", "[MaxHeap]") {

    GIVEN("A MaxHeap with 1 element") {
        MaxHeap<int> aMaxHeap;
        aMaxHeap.insert(38);
        REQUIRE(aMaxHeap.getSize() == 1);

        WHEN("The maximum element is requested") {
            int maxElem = aMaxHeap.getMax();

            THEN("It will be the element that was inserted") {
                REQUIRE(maxElem == 38);
            }
            AND_THEN("The size will not change") {
                REQUIRE(aMaxHeap.getSize() == 1);
            }
        }
        WHEN("The maximum element is popped") {
            int maxElem = aMaxHeap.pop();

            THEN("It will be the element that was inserted") {
                REQUIRE(maxElem == 38);
            }
            AND_THEN("The size will decrease") {
                REQUIRE(aMaxHeap.getSize() == 0);
            }
            AND_THEN("Popping again will throw an error") {
                REQUIRE_THROWS_AS(maxElem = aMaxHeap.pop(), std::out_of_range);
            }
        }
    }

    GIVEN("A MaxHeap with some elements") {
        MaxHeap<int> aMaxHeap;
        aMaxHeap.insert(5);
        aMaxHeap.insert(1);
        aMaxHeap.insert(6);
        aMaxHeap.insert(4);
        REQUIRE(aMaxHeap.getSize() == 4);

        WHEN("The maximum element is requested") {
            int maxElem = aMaxHeap.getMax();

            THEN("It will be the maximum element from the MaxHeap") {
                REQUIRE(maxElem == 6);
            }
        }
        WHEN("The maximum element is popped") {
            aMaxHeap.pop();

            THEN("The maximum element will change") {
                REQUIRE(aMaxHeap.getMax() == 5);
                REQUIRE(aMaxHeap.getSize() == 3);
            }
        }
    }

    GIVEN("A MaxHeap elements inserted from smallest to biggest") {
        MaxHeap<int> aMaxHeap;
        for (int i = 1; i <= 1000; ++i) {
            aMaxHeap.insert(i);
        }

        WHEN("The elements are popped off one by one") {
            THEN("They will be popped off biggest to smallest") {
                for (size_t i = 1000; i >= 1; --i) {
                    REQUIRE(aMaxHeap.getSize() == i);
                    REQUIRE(aMaxHeap.getMax() == (int)i);
                    REQUIRE(aMaxHeap.pop() == (int)i);
                }
            }
        }
    }

    GIVEN("A MaxHeap elements inserted from biggest to smallest") {
        MaxHeap<int> aMaxHeap;
        for (int i = 1000; i >= 1; --i) {
            aMaxHeap.insert(i);
        }

        WHEN("The elements are popped off one by one") {
            THEN("They will be popped off biggest to smallest") {
                for (size_t i = 1000; i >= 1; --i) {
                    REQUIRE(aMaxHeap.getSize() == i);
                    REQUIRE(aMaxHeap.pop() == (int)i);
                }
            }
        }
    }
}