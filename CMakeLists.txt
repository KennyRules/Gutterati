cmake_minimum_required( VERSION 3.0 )

project( Gutterati )

set( Gutterati_VERSION_MAJOR 0 )
set( Gutterati_VERSION_MINOR 1 )
set( Gutterati_VERSION_PATCH 1 )

# set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
# set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
# set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

set( CMAKE_CXX_STANDARD 11 )

if(MSVC)
  	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    	string(REGEX REPLACE "/W[0-4]" "/W4 /WX" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  	else()
    	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Werror -Wno-unknown-pragmas")
endif()


set( GUTTERATI_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

include_directories(  ${GUTTERATI_DIR}/src )
include_directories(  ${GUTTERATI_DIR}/include )

file( GLOB Gutterati_SRC 
    "${GUTTERATI_DIR}/src/*.h"
)

file( GLOB Gutterati_Test_DS_SRC 
    "${GUTTERATI_DIR}/tests/data_structures/*.cpp"
)

set( Gutterati_Test_MAIN ${GUTTERATI_DIR}/tests/GutteratiTestMain.cpp )

add_executable( TestGutterati ${Gutterati_Test_MAIN} ${Gutterati_Test_DS_SRC} )

set_target_properties( TestGutterati PROPERTIES OUTPUT_NAME_DEBUG TestGutterati-debug )
set_target_properties( TestGutterati PROPERTIES OUTPUT_NAME_RELEASE TestGutterati-release )

add_custom_target( Gutterati SOURCES ${Gutterati_SRC} )

enable_testing()
add_test( NAME RunTests COMMAND "$<TARGET_FILE:TestGutterati>" )
