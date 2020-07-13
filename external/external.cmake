#========================================================================================

INCLUDE_DIRECTORIES( external )

include( ${CMAKE_CURRENT_LIST_DIR}/vlibs.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/zcm_types.cmake )
include( ${VLIBS_DIR}/cmake/pthread.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/niias_srv_supply/niias_srv_supply.cmake )

add_executable( ${V_HEADERS} ${V_SOURCES} ${ZCM_TYPES} )

#========================================================================================
