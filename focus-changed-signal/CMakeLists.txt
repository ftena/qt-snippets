cmake_minimum_required(VERSION 3.16)
project(focus_changed_signal VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(focus_changed_signal WIN32 MACOSX_BUNDLE
    dialog.cpp dialog.h dialog.ui
    main.cpp
)
target_link_libraries(focus_changed_signal PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
