## application name
set( APP_NAME "testing_widgets" )

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
find_package(Qt5Test REQUIRED)
find_package(Qt5Widgets REQUIRED)

        include_directories(${Qt5Widgets_INCLUDE_DIRS})
        include_directories(${Qt5Core_INCLUDE_DIRS})
        include_directories(${Qt5Gui_INCLUDE_DIRS})
        include_directories(${Qt5Designer_INCLUDE_DIRS})
        include_directories(${Qt5Concurrent_INCLUDE_DIRS})
        include_directories(${Qt5Svg_INCLUDE_DIRS})

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
target_link_libraries( ${APP_NAME} Qt5::Widgets Qt5::Test )

## enable testing 
enable_testing ()
add_test( ${APP_NAME} ${APP_NAME} )
