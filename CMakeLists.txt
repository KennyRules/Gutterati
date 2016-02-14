cmake_minimum_required(VERSION 3.0)

project(Gutterati)

set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)
set (Tutorial_VERSION_PATCH 0)


MESSAGE( STATUS "Binary Dir: " ${CMAKE_BINARY_DIR} )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

get_filename_component(GUTTERATI_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PATH)

file(GLOB Gutterati_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(Gutterati ${Gutterati_SRC})