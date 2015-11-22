# Automatically generated file, do not edit
SET(BII_IS_DEP False)


# LIBRARY user_Gutterati ##################################
# with interface user_Gutterati_interface

# Source code files of the library
SET(BII_LIB_SRC  )
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS user_Gutterati_interface )
# System included headers
SET(BII_LIB_SYSTEM_HEADERS )
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES examples_LinkedListTest)

SET(BII_BLOCK_TESTS )


# EXECUTABLE examples_LinkedListTest ##################################

SET(BII_examples_LinkedListTest_SRC examples/LinkedListTest.cpp
			src/LinkedList.h)
SET(BII_examples_LinkedListTest_DEPS user_Gutterati_interface user_Gutterati)
# System included headers
SET(BII_examples_LinkedListTest_SYSTEM_HEADERS )
# Required include paths
SET(BII_examples_LinkedListTest_INCLUDE_PATHS )
