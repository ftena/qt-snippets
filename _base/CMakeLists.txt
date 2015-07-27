## application name
set( APP_NAME "base" )

## project name
project( ${APP_NAME} )

## require a minimum version of CMake
cmake_minimum_required ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
add_definitions( -Wall -O2 )
set( CMAKE_CXX_FLAGS -g )

## include (or not) the full compiler output
set( CMAKE_VERBOSE_MAKEFILE OFF )

## required packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

## sources
file( GLOB MAIN_SRC *.cpp )
set( SOURCES ${MAIN_SRC} )

## executable
add_executable( ${APP_NAME} ${SOURCES} )

## link
target_link_libraries( ${APP_NAME} Qt5::Widgets )

