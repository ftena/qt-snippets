cmake_minimum_required(VERSION 3.16)
project(stylesheet VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(stylesheet WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
)
target_link_libraries(stylesheet PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)


# Resources:
set(stylesheet_resource_files
    "qss/blue.qss"
    "qss/cool.qss"
    "qss/cool_v2.qss"
    "qss/main_window_background.qss"
    "qss/pushbutton_border_image.qss"
    "qss/pushbutton_image_centered.qss"
    "qss/stack.qss"
    "qss/transparent.qss"
)

qt_add_resources(stylesheet "stylesheet"
    PREFIX
        "/"
    FILES
        ${stylesheet_resource_files}
)
set_source_files_properties("images/icon.png"
    PROPERTIES QT_RESOURCE_ALIAS "icon"
)
set(stylesheet1_resource_files
    "images/icon.png"
)
