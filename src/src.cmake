#========================================================================================

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

#========================================================================================

include( ${CMAKE_CURRENT_LIST_DIR}/defs/defs.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/config/config.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/publish/publish.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/subscribe/subscribe.cmake )

#========================================================================================

set( SRC
    ${DEFS}
    ${CONFIG}
    ${PUBLISH}
    ${SUBSCRIBE} )

#========================================================================================
