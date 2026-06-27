cmake_minimum_required(VERSION 3.16)
project(qml-mouse-events VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml Quick Widgets)

qt_standard_project_setup()

qt_add_executable(qml-mouse-events WIN32 MACOSX_BUNDLE
    main.cpp
)
qt_add_qml_module(qml-mouse-events
    URI qml_mouse_events
    VERSION ${PROJECT_VERSION}
    QML_FILES
        main.qml
    RESOURCES
        images/icon.png
    NO_RESOURCE_TARGET_PATH
)

target_link_libraries(qml-mouse-events PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::Widgets
)

