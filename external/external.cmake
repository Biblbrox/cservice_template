#========================================================================================

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

#========================================================================================

include( ${CMAKE_CURRENT_LIST_DIR}/vlibs.cmake )
include( ${VLIBS_DIR}/cmake/pthread.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/niias_srv_supply/niias_srv_supply.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/zcm_types.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/vzcm/vzcm.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/cpp_codestyle/codestyle.cmake )

#========================================================================================

set( EXTERNAL
    ${V_HEADERS}
    ${V_SOURCES}
    ${ZCM_TYPES}
    ${CODE_STYLE} )

#========================================================================================
