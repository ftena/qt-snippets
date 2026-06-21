cmake_minimum_required(VERSION 3.16)
project(tabs VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(tabs WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
)
target_link_libraries(tabs PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(tabs PRIVATE
    )
endif()
