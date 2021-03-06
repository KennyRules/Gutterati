#include "catch.hpp"
#include "ArrayList.h"

SCENARIO("An ArrayList can hold elements in a contiguous block of memory", "[ArrayList]") {

    GIVEN("An ArrayList with 1 element") {
        ArrayList<int> anArrayList(1);

        WHEN("The size is queried") {
            THEN("The size is 1") {
                REQUIRE(anArrayList.getSize() == 1);
            }
        }
    }

    GIVEN("An ArrayList with explicit size 0") {
        WHEN("It is created") {
            THEN("It throws an error") {
                REQUIRE_THROWS_AS(ArrayList<int> anArrayList(0), std::invalid_argument);
            }
        }
    }

    GIVEN("A new ArrayList with size of 10") {
        ArrayList<int> anArrayList(10);

        WHEN("Elements [0,9] are initially accessed") {

            THEN("They will all be 0") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(anArrayList[i] == 0);
                }
            }
        }
        AND_WHEN("Elements above 9 are accessed") {

            THEN("It will throw a error") {
                REQUIRE_THROWS_AS(anArrayList[10], std::out_of_range);
            }
        }
        AND_WHEN("Elements in the array are assigned new values") {
            for (size_t i = 0; i < 10; ++i) {
                anArrayList[i] = i + 5;
            }

            THEN("They will retain those new values assigned") {
                for (int i = 0; i < 10; ++i) {
                    REQUIRE(anArrayList[(size_t)i] == i + 5);
                }
            }
        }
        AND_WHEN("The size is queried") {

            THEN("It will be 10") {
                REQUIRE(anArrayList.getSize() == 10);
            }
        }
        AND_WHEN("A new element is added") {
            anArrayList.insert(11);

            THEN("The size will grow by 1") {
                REQUIRE(anArrayList.getSize() == 11);
            }
            AND_THEN("The new element will be in the array") {
                REQUIRE(anArrayList[10] == 11);
            }
        }
    }
}

SCENARIO("An ArrayList can grow as more elements are added", "[ArrayList]") {

    GIVEN("An ArrayList with 1 element") {

        ArrayList<int> anArrayList(1);
        anArrayList[0] = 1;
        REQUIRE(anArrayList.getSize() == 1);
        REQUIRE(anArrayList.getCapacity() == 2);
        REQUIRE(anArrayList[0] == 1);

        WHEN("A new element is added") {
            anArrayList.insert(2);

            THEN("The size and capacity will grow") {
                REQUIRE(anArrayList.getSize() == 2);
                REQUIRE(anArrayList.getCapacity() == 3);
            }
            AND_THEN("The original and new elements will exist in the ArrayList") {
                REQUIRE(anArrayList[0] == 1);
                REQUIRE(anArrayList[1] == 2);
            }
        }

        AND_WHEN("Two new element are added") {
            anArrayList.insert(2);
            anArrayList.insert(3);

            THEN("The size and capacity will grow") {
                REQUIRE(anArrayList.getSize() == 3);
                REQUIRE(anArrayList.getCapacity() == 5);
            }
            AND_THEN("The original and new elements will exist in the ArrayList") {
                REQUIRE(anArrayList[0] == 1);
                REQUIRE(anArrayList[1] == 2);
                REQUIRE(anArrayList[2] == 3);
            }
        }
    }

    GIVEN("A new ArrayList with size of 10 and elements initialized") {
        ArrayList<int> originalArrayList(10);
        for (size_t i = 0; i < 10; ++i) {
            originalArrayList[i] = i * 30;
        }

        WHEN("A new ArrayList is created using the original ArrayList") {
            ArrayList<int> newArrayList(originalArrayList);

            THEN("The new ArrayList has the same elements as the original ArrayList") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(originalArrayList[i] == newArrayList[i]);
                }
                REQUIRE(originalArrayList.getCapacity() == newArrayList.getCapacity());
                REQUIRE(originalArrayList.getSize() == newArrayList.getSize());
            }
            AND_THEN("Changing the elements in the original ArrayList does not change the new one") {
                originalArrayList[5] = -131;
                REQUIRE(originalArrayList[5] != newArrayList[5]);
            }
        }
        AND_WHEN("A new ArrayList is created using the original ArrayList via assignment") {
            ArrayList<int> newArrayList = originalArrayList;

            THEN("The new ArrayList has the same elements as the original ArrayList") {
                for (size_t i = 0; i < 10; ++i) {
                    REQUIRE(originalArrayList[i] == newArrayList[i]);
                }
                REQUIRE(originalArrayList.getCapacity() == newArrayList.getCapacity());
                REQUIRE(originalArrayList.getSize() == newArrayList.getSize());
            }
            AND_THEN("Changing the elements in the original ArrayList does not change the new one") {
                originalArrayList[5] = -131;
                REQUIRE(originalArrayList[5] != newArrayList[5]);
            }
        }
    }
}

SCENARIO("An ArrayList can have elements removed", "[ArrayList]") {

    GIVEN("An ArrayList with no elements") {
        ArrayList<char> anArrayList;
        REQUIRE(anArrayList.getSize() == 0);
        REQUIRE(anArrayList.getCapacity() == 0);

        WHEN("That last element is attempted to be removed") {
            THEN("It throws an error") {
                REQUIRE_THROWS_AS(anArrayList.removeLast(), std::out_of_range);
            }
            AND_THEN("The size remains 0") {
                REQUIRE(anArrayList.getSize() == 0);
                REQUIRE(anArrayList.getCapacity() == 0);
            }
        }
    }

    GIVEN("An ArrayList with some elements") {
        ArrayList<char> anArrayList;
        anArrayList.insert('a');
        anArrayList.insert('b');
        anArrayList.insert('c');
        anArrayList.insert('d');
        REQUIRE(anArrayList.getSize() == 4);
        REQUIRE(anArrayList.getCapacity() == 5);
        REQUIRE(anArrayList[0] == 'a');
        REQUIRE(anArrayList[1] == 'b');
        REQUIRE(anArrayList[2] == 'c');
        REQUIRE(anArrayList[3] == 'd');

        WHEN("Elements are removed") {
            anArrayList.removeLast();

            THEN("The size shrinks") {
                REQUIRE(anArrayList.getSize() == 3);

                anArrayList.removeLast();
                anArrayList.removeLast();
                anArrayList.removeLast();
                REQUIRE(anArrayList.getSize() == 0);
            }
            AND_THEN("Accessing the removed elements isn't allowed") {
                REQUIRE_THROWS_AS(anArrayList[3], std::out_of_range);
            }
        }
    }
}