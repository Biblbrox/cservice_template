#========================================================================================

set( VLIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vlibs2" )

#========================================================================================

include( "${VLIBS_DIR}/cmake/vcmdline_parser.cmake" )
include( "${VLIBS_DIR}/cmake/vgit.cmake" )
include( "${VLIBS_DIR}/cmake/vlog.cmake" )
include( "${VLIBS_DIR}/cmake/vsettings.cmake" )

#========================================================================================

set( V_LIBS ${V_HEADERS} ${V_SOURCES} )

#========================================================================================
