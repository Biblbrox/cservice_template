#========================================================================================

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

#========================================================================================

include( ${CMAKE_CURRENT_LIST_DIR}/defs/defs.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/config/config.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/publisher/publisher.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/subscriber/subscriber.cmake )

#========================================================================================

set( SRC
    ${DEFS}
    ${CONFIG}
    ${PUBLISHER}
    ${SUBSCRIBER} )

#========================================================================================
