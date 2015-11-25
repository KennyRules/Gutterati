#pragma once
#define CATCH_CONFIG_RUNNER

#include "../src/SingleLinkedList.h"
#include "../include/catch.hpp"

TEST_CASE("SingleLinkedList - Adding elements.", "[SingleLinkedList]")
{
    SingleLinkedList list;
    REQUIRE(list.size() == 0);

    SECTION("Adding elements increases size.") {
        list.add(0);
        REQUIRE(list.size() == 1);

        for (int i = 0; i < 10; ++i) {
            list.add(i);
        }

        REQUIRE(list.size() == 11);
    }
};

TEST_CASE("SingleLinkedList - Removing elements.", "[SingleLinkedList]") 
{
    SingleLinkedList list;
    REQUIRE(list.size() == 0);

    SECTION("Deleting non-existent elements allowed.") {
        list.remove(0);
        REQUIRE(list.size() == 0);
    }

    SECTION("Deleting existent elements reduces size.") {
        list.add(0);
        REQUIRE(list.size() == 1);
        list.remove(0);
        REQUIRE(list.size() == 0);
    }

    SECTION("Deleting head.") {
        list.add(1);
        list.add(2);
        REQUIRE(list.size() == 2);
        list.remove(1);
        REQUIRE(list.size() == 1);
    }

    SECTION("Deleting tail.") {
        list.add(1);
        list.add(2);
        REQUIRE(list.size() == 2);
        list.remove(2);
        REQUIRE(list.size() == 1);
    }

    SECTION("Deleting middle.") {
        for (int i = 0; i < 3; ++i)
            list.add(i);
        REQUIRE(list.size() == 3);
        list.remove(1);
        REQUIRE(list.size() == 2);
    }
};

int main(int argc, char **argv) 
{
    int result = Catch::Session().run(argc, argv);
    return result;
}