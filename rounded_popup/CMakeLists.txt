cmake_minimum_required(VERSION 3.16)
project(rounded_popup VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(rounded_popup WIN32 MACOSX_BUNDLE
    dialog.cpp dialog.h dialog.ui
    main.cpp
)
target_link_libraries(rounded_popup PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)


# Resources:
set(stylesheet_resource_files
    "qss/style.qss"
)

qt_add_resources(rounded_popup "stylesheet"
    PREFIX
        "/"
    FILES
        ${stylesheet_resource_files}
)
