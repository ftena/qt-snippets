## application name
set( APP_NAME "translation" )

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
find_package(Qt6 REQUIRED COMPONENTS LinguistTools)

include_directories(${Qt6Widgets_INCLUDE_DIRS})
include_directories(${Qt6Core_INCLUDE_DIRS})
include_directories(${Qt6Gui_INCLUDE_DIRS})

# Get the name of the rcc executable. This bin will be used later.
set ( QT_RCC_EXE Qt6::rcc )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTORCC ON )

## sources
file( GLOB MAIN_SRC *.cpp )
set( SOURCES ${MAIN_SRC} )

# Language directory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/res/translations)

set( trans_file languages )
set( trans_qrcfile ${CMAKE_CURRENT_SOURCE_DIR}/res/${trans_file}.qrc )

## executable
add_executable( ${APP_NAME} ${trans_qrcfile} ${SOURCES} )

# Process translations_target
add_dependencies (${APP_NAME} translations_target)

## link
target_link_libraries( ${APP_NAME} Qt6::Widgets )

