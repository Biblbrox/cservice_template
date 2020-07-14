#========================================================================================

include_directories( external )

include( ${CMAKE_CURRENT_LIST_DIR}/vlibs.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/zcm_types.cmake )
include( ${VLIBS_DIR}/cmake/pthread.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/niias_srv_supply/niias_srv_supply.cmake )

set( EXTERNAL
    ${V_HEADERS}
    ${V_SOURCES}
   )

#========================================================================================
