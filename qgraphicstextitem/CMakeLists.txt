cmake_minimum_required(VERSION 3.16)
project(qgraphicstextitem VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(qgraphicstextitem WIN32 MACOSX_BUNDLE
    graphicstextitem_1.cpp graphicstextitem_1.h
    graphicstextitem_2.cpp graphicstextitem_2.h
    graphicstextitem_3.cpp graphicstextitem_3.h
    main.cpp
)
target_link_libraries(qgraphicstextitem PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
