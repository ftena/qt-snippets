cmake_minimum_required(VERSION 3.16)
project(qml-repeater VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml Quick Widgets)

qt_standard_project_setup()

qt_add_executable(qml-repeater WIN32 MACOSX_BUNDLE
    main.cpp
)
qt_add_qml_module(qml-repeater
    URI qml_repeater
    VERSION ${PROJECT_VERSION}
    QML_FILES
        main.qml
    NO_RESOURCE_TARGET_PATH
)

target_link_libraries(qml-repeater PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::Widgets
)

