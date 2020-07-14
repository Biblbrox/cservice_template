#========================================================================================

project( cservice_template )

#========================================================================================

cmake_minimum_required( VERSION 3.10 )

#========================================================================================

add_definitions( -DGUI )
add_definitions( -DTRACE )

#========================================================================================

#set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_BUILD_TYPE "Debug" )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

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
    main.cpp
    ${EXTERNAL} )

target_link_libraries( ${PROJECT_NAME}
    ${V_LIBRARIES}
    -ldl )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================
