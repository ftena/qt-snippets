file(GLOB TRANSLATIONS_FILES ${CMAKE_SOURCE_DIR}/res/translations/*.ts )
file(GLOB_RECURSE CPP_FILES ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE UI_FILES ${CMAKE_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/*.h)

set (FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${CPP_FILES} ${UI_FILES} ${HEADER_FILES})

# This option is OFF by default, and it is set in CMakeCache.txt
# If you need to update the ts files, set the option ON
# ex: option (UPDATE_TRANSLATIONS "Update source translation/*.ts" ON)  
option (UPDATE_TRANSLATIONS "Update source translation/*.ts" ON)

if (UPDATE_TRANSLATIONS	)
	# Generates commands to update .ts (via lupdate) and .qm (via lrelease).
	qt5_create_translation(QM_FILES ${FILES_TO_TRANSLATE} ${TRANSLATIONS_FILES})
else (UPDATE_TRANSLATIONS)
	# It generates commands to create .qm from .ts.
	qt5_add_translation(QM_FILES ${TRANSLATIONS_FILES})
endif (UPDATE_TRANSLATIONS)

add_custom_target (translations_target DEPENDS ${QM_FILES})

install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/res/translations)

# prevent the generated files from being deleted during make clean
set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM true)

