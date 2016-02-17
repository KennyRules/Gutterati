cmake_minimum_required( VERSION 2.8 )

project( Gutterati )

set( Gutterati_VERSION_MAJOR 0 )
set( Gutterati_VERSION_MINOR 1 )
set( Gutterati_VERSION_PATCH 0 )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

set( CMAKE_CXX_STANDARD 11 )

set( GUTTERATI_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

include_directories( ${GUTTERATI_DIR}/include ${GUTTERATI_DIR}/src )

file( GLOB Gutterati_SRC 
    "${GUTTERATI_DIR}/src/*.h"
)

file( GLOB Gutterati_Test_DS_SRC 
    "${GUTTERATI_DIR}/tests/data_structures/*.cpp"
)

set( Gutterati_Test_MAIN ${GUTTERATI_DIR}/tests/GutteratiTestMain.cpp )

add_executable( TestGutterati ${Gutterati_Test_MAIN} ${Gutterati_Test_DS_SRC} ${Gutterati_SRC} )

set_target_properties( TestGutterati PROPERTIES OUTPUT_NAME_DEBUG TestGutterati-debug )
set_target_properties( TestGutterati PROPERTIES OUTPUT_NAME_RELEASE TestGutterati-release )

enable_testing()
add_test( NAME RunTests COMMAND TestGutterati )
