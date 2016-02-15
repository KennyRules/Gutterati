cmake_minimum_required( VERSION 3.0 )

project( Gutterati )

set ( Tutorial_VERSION_MAJOR 0 )
set ( Tutorial_VERSION_MINOR 1 )
set ( Tutorial_VERSION_PATCH 0 )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}" )

set( GUTTERATI_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

file( GLOB Gutterati_SRC
    "${GUTTERATI_DIR}/src/*.h"
)

set( Gutterati_Test_SRC ${GUTTERATI_DIR}/tests/GutteratiTestMain.cpp )

file( GLOB Gutterati_Test_DS_SRC 
    "${GUTTERATI_DIR}/tests/data_structures/*.cpp"
)

include_directories(${GUTTERATI_DIR}/include)

add_executable( TestGutterati ${Gutterati_Test_SRC} ${Gutterati_Test_DS_SRC} )
