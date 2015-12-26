/** 
 *  @file
 *  @brief Central hub for running Catch tests.
 *  TO-DO: Linkup to LinkedListTest.cpp
 **/

#define CATCH_CONFIG_RUNNER

#include "../include/catch.hpp"

/**
 * @brief Main method that will just run Catch.
 * 
 * @param argc Number of arguments in argv
 * @param argv Extra options passed in.
 */
int main(int argc, char* const argv[])
{
    int result = Catch::Session().run(argc, argv);

    return result;
}
