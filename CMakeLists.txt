#========================================================================================

project( cservice_template )

#========================================================================================

cmake_minimum_required( VERSION 3.10 )

#========================================================================================

option( GUI FALSE )

if ( GUI )
    add_definitions( -DGUI )
    set( CMAKE_BUILD_TYPE "Debug" )
else()
    set( CMAKE_BUILD_TYPE "Release" )
endif()

#========================================================================================

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-dev" )

#========================================================================================

include( ${CMAKE_CURRENT_SOURCE_DIR}/external/external.cmake )

#========================================================================================

include_directories( ${CMAKE_SOURCE_DIR} )

include( ${CMAKE_CURRENT_SOURCE_DIR}/cfg/cfg.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/src/src.cmake )

#========================================================================================

add_executable( ${PROJECT_NAME}
    ${CFG}
    ${SRC}
    ${EXTERNAL} )

target_link_libraries( ${PROJECT_NAME}
    ${VTK_LIBRARIES}
    ${PCL_LIBRARIES}
    ${V_LIBRARIES}
    -ldl )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================
