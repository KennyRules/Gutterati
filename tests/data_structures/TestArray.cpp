#include "catch.hpp"
#include "Array.h"

SCENARIO("An Array can hold elements in a contiguous block of memory", "[Array]") {

    GIVEN("An Array with 1 element") {
        Array<int> anArray(1);

        WHEN("The size is queried") {
            THEN("The size is 1") {
                REQUIRE(anArray.getSize() == (size_t)1);
            }
        }
    }

    GIVEN("An Array with size 0") {
        WHEN("It is created") {
            THEN("It throws an error") {
                REQUIRE_THROWS_AS(Array<int> anArray(0), std::invalid_argument);
            }
        }
    }

    GIVEN("A new Array with size of 10") {
        Array<int> anArray(10);

        WHEN("Elements [0,9] are initially accessed") {

            THEN("They will all be 0") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(anArray[i] == 0);
                }
            }
        }
        AND_WHEN("Elements above 9 are accessed") {

            THEN("It will throw a error") {
                REQUIRE_THROWS_AS(anArray[10u], std::out_of_range);
            }
        }
        AND_WHEN("Elements in the array are assigned new values") {
            for (size_t i = 0; i < 10; i++) {
                anArray[i] = i + 5;
            }

            THEN("They will retain those new values assigned") {
                for (int i = 0; i < 10; i++) {
                    REQUIRE(anArray[(size_t)i] == i + 5);
                }
            }
        }
        AND_WHEN("The size is queried") {

            THEN("It will be 10") {
                REQUIRE(anArray.getSize() == 10);
            }
        }
        
    }

    GIVEN("A new Array with size of 10 and elements initialized") {
        Array<int> originalArray(10);
        for (size_t i = 0; i < 10; ++i) {
            originalArray[i] = i * 20;
        }

        WHEN("A new Array is created using the original Array") {
            Array<int> newArray(originalArray);

            THEN("The new Array has the same elements as the original Array") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(originalArray[i] == newArray[i]);
                }
                REQUIRE(originalArray.getSize() == newArray.getSize());
            }
            AND_THEN("Changing the elements in the original Array does not change the new one") {
                originalArray[0] = -42;
                REQUIRE(originalArray[0] != newArray[0]);
            }
        }
        AND_WHEN("A new Array is created using the original Array via assignment") {
            Array<int> newArray = originalArray;

            THEN("The new Array has the same elements as the original Array") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(originalArray[i] == newArray[i]);
                }
                REQUIRE(originalArray.getSize() == newArray.getSize());
            }
            AND_THEN("Changing the elements in the original Array does not change the new one") {
                originalArray[0] = -13;
                REQUIRE(originalArray[0] != newArray[0]);
            }
        }
    }
}

SCENARIO("An Array can have its elements cleared", "[Array]") {
    
    GIVEN("An Array with some elements") {
        Array<int> anArray(10);
        for (int i = 1; i < 10; ++i) {
            anArray[(size_t)i - 1u] = i;
        }

        WHEN("The Array is cleared") {
            anArray.clear();

            THEN("The elements will all be 0") {
                for (size_t i = 0; i < anArray.getSize(); ++i) {
                    REQUIRE(anArray[i] == 0);
                }
            }
        }
    }
}