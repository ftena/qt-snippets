cmake_minimum_required(VERSION 3.16)
project(test VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Xml)
find_package(Qt6 OPTIONAL_COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(test WIN32 MACOSX_BUNDLE
    main.cpp
)
target_link_libraries(test PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Xml
)


# Resources:
set(res_resource_files
    "myxml.xml"
    "myxml_error.xml"
)

qt_add_resources(test "res"
    PREFIX
        "/"
    FILES
        ${res_resource_files}
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(test PRIVATE
        Qt::Widgets
    )
endif()

