cmake_minimum_required(VERSION 3.16)
project(qml-audio VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml Quick)

qt_standard_project_setup()

qt_add_executable(qml-audio WIN32 MACOSX_BUNDLE
    main.cpp
)
qt_add_qml_module(qml-audio
    URI qml_audio
    VERSION ${PROJECT_VERSION}
    QML_FILES
        main.qml
    RESOURCES
        res/kid_giggle.mp3
        res/kid_giggle.wav
    NO_RESOURCE_TARGET_PATH
)

target_link_libraries(qml-audio PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)
