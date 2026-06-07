cmake_minimum_required(VERSION 3.16)
project(event-filters VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(event-filters WIN32 MACOSX_BUNDLE
    main.cpp
    mywindow.cpp mywindow.h
)
target_link_libraries(event-filters PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

# Resources:
set_source_files_properties("images/icon.png"
    PROPERTIES QT_RESOURCE_ALIAS "icon"
)
set(event-filters_resource_files
    "images/icon.png"
)

qt_add_resources(event-filters "event-filters"
    PREFIX
        "/"
    FILES
        ${event-filters_resource_files}
)