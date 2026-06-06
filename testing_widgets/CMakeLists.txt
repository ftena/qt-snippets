## application name
set( APP_NAME "testing_widgets" )

## project name
project( ${APP_NAME} )

## require a minimum version of CMake
cmake_minimum_required ( VERSION 3.25 FATAL_ERROR )

## add definitions, compiler switches, etc.
add_definitions( -Wall -O2 )
set( CMAKE_CXX_FLAGS -g )

## include (or not) the full compiler output
set( CMAKE_VERBOSE_MAKEFILE OFF )

## required packages
find_package(Qt6Test REQUIRED)
find_package(Qt6Widgets REQUIRED)

        include_directories(${Qt6Widgets_INCLUDE_DIRS})
        include_directories(${Qt6Core_INCLUDE_DIRS})
        include_directories(${Qt6Gui_INCLUDE_DIRS})
        include_directories(${Qt6Designer_INCLUDE_DIRS})
        include_directories(${Qt6Concurrent_INCLUDE_DIRS})
        include_directories(${Qt6Svg_INCLUDE_DIRS})

# important! the next line is for enabling Qt Test
set( QT_USE_QTTEST TRUE )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

## sources
file( GLOB MAIN_SRC *.cpp )
set( SOURCES ${MAIN_SRC} )

## executable
add_executable( ${APP_NAME} ${SOURCES} )

## link
target_link_libraries( ${APP_NAME} Qt6::Widgets Qt6::Test )

## enable testing
enable_testing ()
add_test( ${APP_NAME} ${APP_NAME} )
