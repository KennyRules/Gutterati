#include "../../include/catch.hpp"
#include "../../src/Array.h"

SCENARIO("An Array can hold elements in a contiguous block of memory", "[Array]") {

    GIVEN("An Array with 1 element") {
        Array<int> anArray(1);

        WHEN("The size is queried") {
            THEN("The size is 1") {
                REQUIRE(anArray.getSize() == 1);
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

        WHEN("Elements [0,9] are intiailly accessed") {

            THEN("They will all be 0") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(anArray[i] == 0);
                }
            }
        }
        AND_WHEN("Elements below 0 or above 9 are accessed") {

            THEN("It will throw a error") {
                REQUIRE_THROWS_AS(anArray[-1], std::out_of_range);
                REQUIRE_THROWS_AS(anArray[10], std::out_of_range);
            }
        }
        AND_WHEN("Elements in the array are assigned new values") {
            for (size_t i = 0; i < 10; i++) {
                anArray[i] = i + 5;
            }

            THEN("They will retain those new values assigned") {
                for (size_t i = 0; i < 10; i++) {
                    REQUIRE(anArray[i] == i + 5);
                }
            }
        }
        AND_WHEN("The size is quieried") {

            THEN("It will be 10") {
                REQUIRE(anArray.getSize() == 10);
            }
        }
    }
}