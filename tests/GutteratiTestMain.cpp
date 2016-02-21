/** 
 *  @file
 *  @brief Central hub for running Catch tests.
 **/

#define CATCH_CONFIG_RUNNER

#pragma warning(push, 0)
#include "catch.hpp"
#pragma warning(pop)

/**
 * @brief Main method that will just run Catch.
 * 
 * @param argc Number of arguments in argv
 * @param argv Extra options passed in.
 */
int main(int argc, const char* argv[])
{
    int result = Catch::Session().run(argc, argv);

    return result;
}
