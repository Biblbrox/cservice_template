#========================================================================================

set( VLIBS_DIR "${CMAKE_CURRENT_LIST_DIR}/vlibs2" )

message( "VLIBS_DIR" ${VLIBS_DIR} )

#========================================================================================

include( "${VLIBS_DIR}/cmake/vsettings.cmake" )
include( "${VLIBS_DIR}/cmake/pthread.cmake" )
include( "${VLIBS_DIR}/cmake/vgit.cmake" )
include( "${VLIBS_DIR}/cmake/vlog.cmake" )

#========================================================================================

set( V_LIBS ${V_HEADERS} ${V_SOURCES} )

#========================================================================================
