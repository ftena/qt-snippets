cmake_minimum_required(VERSION 3.16)
project(popup_qpushbutton VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(popup_qpushbutton WIN32 MACOSX_BUNDLE
    dialog.cpp dialog.h dialog.ui
    main.cpp
    popupmenu.cpp popupmenu.h
)
target_link_libraries(popup_qpushbutton PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

