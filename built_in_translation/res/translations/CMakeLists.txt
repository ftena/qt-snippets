file(GLOB TRANSLATIONS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/res/translations/*.ts)
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES es)

set (FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${CPP_FILES} ${UI_FILES} ${HEADER_FILES})

qt_add_translations(TARGETS ${APP_NAME})

add_custom_target (translations_target DEPENDS ${QM_FILES})

# prevent the generated files from being deleted during make clean
#set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM true)

