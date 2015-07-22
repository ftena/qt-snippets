## application name
set( APP_NAME "translation" )

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
find_package(Qt5LinguistTools REQUIRED)

# Get the name of the rcc executable. This bin will be used later.
set ( QT_RCC_EXE ${Qt5Core_RCC_EXECUTABLE} )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

## sources
file( GLOB MAIN_SRC *.cpp )
set( SOURCES ${MAIN_SRC} )

### Languages & translations ###

# Language directory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/res/translations)

set( trans_file languages )
set( trans_srcfile ${CMAKE_CURRENT_SOURCE_DIR}/res/${trans_file}.qrc )
set( trans_infile ${CMAKE_CURRENT_BINARY_DIR}/res/${trans_file}.qrc )
set( trans_outfile ${CMAKE_CURRENT_BINARY_DIR}/qrc_${trans_file}.cxx )

# Copy the QRC file to the output directory, because the files listed in the
# qrc file are relative to that directory.
ADD_CUSTOM_COMMAND(
    OUTPUT ${trans_infile}
    COMMAND ${CMAKE_COMMAND} -E copy ${trans_srcfile} ${trans_infile}
    MAIN_DEPENDENCY ${trans_srcfile}
    )

# Run the resource compiler (rcc_options should already be set). We can't
# use QT_ADD_RESOURCES because the qrc file may not exist yet.
ADD_CUSTOM_COMMAND(
    OUTPUT ${trans_outfile}    
    COMMAND ${QT_RCC_EXE}
    ARGS ${rcc_options} -name ${trans_file} -o ${trans_outfile} ${trans_infile}
    MAIN_DEPENDENCY ${trans_infile}
    DEPENDS ${qm_files}
    )

## executable
add_executable( ${APP_NAME} ${SOURCES} ${resources_qrc} ${trans_outfile} )

# Process translations_target
add_dependencies (${APP_NAME} translations_target)

## link
target_link_libraries( ${APP_NAME} Qt5::Widgets )

