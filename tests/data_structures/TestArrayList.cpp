#include "../../include/catch.hpp"
#include "../../src/ArrayList.h"

SCENARIO("An ArrayList can hold elements in a contiguous block of memory", "[ArrayList]") {

    GIVEN("An ArrayList with 1 element") {
        ArrayList<int> anArray(1);

        WHEN("The size is queried") {
            THEN("The size is 1") {
                REQUIRE(anArray.getSize() == 1);
            }
        }
    }

    GIVEN("An ArrayList with size 0") {
        WHEN("It is created") {
            THEN("It throws an error") {
                REQUIRE_THROWS_AS(ArrayList<int> anArray(0), std::invalid_argument);
            }
        }
    }

    GIVEN("A new ArrayList with size of 10") {
        ArrayList<int> anArray(10);

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
            for (size_t i = 0; i < 10; ++i) {
                anArray[i] = i + 5;
            }

            THEN("They will retain those new values assigned") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(anArray[i] == i + 5);
                }
            }
        }
        AND_WHEN("The size is quieried") {
            THEN("It will be 10") {
                REQUIRE(anArray.getSize() == 10);
            }
        }
        AND_WHEN("A new element is added") {
            anArray.insert(11);

            THEN("The size will grow by 1") {
                REQUIRE(anArray.getSize() == 11);
            }
        }
    }
}

SCENARIO("An ArrayList can grow as more elements are added", "[ArrayList]") {

    GIVEN("An ArrayList with 1 element") {

        ArrayList<int> anArray(1);
        anArray[0] = 1;
        REQUIRE(anArray.getSize() == 1);
        REQUIRE(anArray.getCapacity() == 2);
        REQUIRE(anArray[0] == 1);

        WHEN("A new element is added") {
            anArray.insert(2);

            THEN("The size and capacity will grow") {
                REQUIRE(anArray.getSize() == 2);
                REQUIRE(anArray.getCapacity() == 3);
            }
            AND_THEN("The original and new elements will exist in the ArrayList") {
                REQUIRE(anArray[0] == 1);
                REQUIRE(anArray[1] == 2);
            }
        }

        AND_WHEN("Two new element are added") {
            anArray.insert(2);
            anArray.insert(3);

            THEN("The size and capacity will grow") {

                REQUIRE(anArray.getSize() == 3);
                REQUIRE(anArray.getCapacity() == 5);
            }
            AND_THEN("The original and new elements will exist in the ArrayList") {
                REQUIRE(anArray[0] == 1);
                REQUIRE(anArray[1] == 2);
                REQUIRE(anArray[2] == 3);
            }
        }
    }

}