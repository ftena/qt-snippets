cmake_minimum_required(VERSION 3.16)
project(key_press_event_in_qframe-31617189 VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(key_press_event_in_qframe-31617189 WIN32 MACOSX_BUNDLE
    main.cpp
    myframe.cpp myframe.h
)
target_link_libraries(key_press_event_in_qframe-31617189 PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

