#========================================================================================

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

include( ${CMAKE_CURRENT_LIST_DIR}/config/config.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/defs/defs.cmake )

set( SRC ${CONFIG} ${DEFS} )

#add_executable(
#    ${CMAKE_PROJECT_NAME}
#    ${CONFIG}
#    ${DEFS}
#    )

#========================================================================================
