#include "catch.hpp"
#include "MinHeap.h"

SCENARIO("A MinHeap can have elements added", "[MinHeap]") {
    
    GIVEN("A empty MinHeap") {
        MinHeap<int> aMinHeap;

        WHEN("The size is queried") {

            THEN("The size is 0") {
                REQUIRE(aMinHeap.getSize() == 0);
            }
            AND_THEN("The MinHeap reports it is empty") {
                REQUIRE(aMinHeap.isEmpty() == true);
            }
        }
        AND_WHEN("Elements are added") {
            aMinHeap.insert(1);
            aMinHeap.insert(2);
            aMinHeap.insert(3);

            THEN("The size increases") {
                REQUIRE(aMinHeap.getSize() == 3);
            }
            AND_THEN("The MinHeap reports it is not empty") {
                REQUIRE(aMinHeap.isEmpty() == false);
            }
        }
    }
}

SCENARIO("A MinHeap can have the minimum element extracted", "[MinHeap]") {
    
    GIVEN("A MinHeap with 1 element") {
        MinHeap<int> aMinHeap;
        aMinHeap.insert(38);
        REQUIRE(aMinHeap.getSize() == 1);

        WHEN("The minimum element is requested") {
            int minElem = aMinHeap.getMin();

            THEN("It will be the element that was inserted") {
                REQUIRE(minElem == 38);
            }
            AND_THEN("The size will not change") {
                REQUIRE(aMinHeap.getSize() == 1);
            }
        }
        WHEN("The minimum element is popped") {
            int minElem = aMinHeap.pop();

            THEN("It will be the element that was inserted") {
                REQUIRE(minElem == 38);
            }
            AND_THEN("The size will decrease") {
                REQUIRE(aMinHeap.getSize() == 0);
            }
            AND_THEN("Popping again will throw an error") {
                REQUIRE_THROWS_AS(minElem = aMinHeap.pop(), std::out_of_range);
            }
        }
    }

    GIVEN("A MinHeap with some elements") {
        MinHeap<int> aMinHeap;
        aMinHeap.insert(5);
        aMinHeap.insert(6);
        aMinHeap.insert(1);
        aMinHeap.insert(4);
        REQUIRE(aMinHeap.getSize() == 4);

        WHEN("The minimum element is requested") {
            int minElem = aMinHeap.getMin();

            THEN("It will be the minimum element from the MinHeap") {
                REQUIRE(minElem == 1);
            }
        }
        WHEN("The minimum element is popped") {
                aMinHeap.pop();

            THEN("The minimum element will change") {
                REQUIRE(aMinHeap.getMin() == 4);
                REQUIRE(aMinHeap.getSize() == 3);
            }
        }
    }

    GIVEN("A MinHeap elements inserted from smallest to biggest") {
        MinHeap<int> aMinHeap;
        for (int i = 0; i < 1000; ++i) {
            aMinHeap.insert(i);
        }

        WHEN("The elements are popped off one by one") {
            THEN("They will be popped off smallest to biggest") {
                for (size_t i = 0; i < 1000; ++i) {
                    REQUIRE(aMinHeap.getSize() == 1000 - i);
                    REQUIRE(aMinHeap.getMin() == (int)i);
                    REQUIRE(aMinHeap.pop() == (int)i);
                }
            }
        }
    }

    GIVEN("A MinHeap elements inserted from biggest to smallest") {
        MinHeap<int> aMinHeap;
        for (int i = 1000; i >= 1; --i) {
            aMinHeap.insert(i);
        }

        WHEN("The elements are popped off one by one") {
            THEN("They will be popped off smallest to biggest") {
                for (size_t i = 1; i <= 1000; ++i) {
                    REQUIRE(aMinHeap.getSize() == 1000 - i + 1);
                    REQUIRE(aMinHeap.pop() == (int)i);
                }
            }
        }
    }
}