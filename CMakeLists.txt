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

include( ${CMAKE_CURRENT_SOURCE_DIR}/vlibs.cmake )
include( ${VLIBS_DIR}/cmake/pthread.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/niias_srv_supply/niias_srv_supply.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/zcm_types.cmake )

#========================================================================================

include_directories( ${CMAKE_SOURCE_DIR} )

include( ${CMAKE_CURRENT_SOURCE_DIR}/config/config.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/defs/defs.cmake )

#========================================================================================

add_executable(
    ${PROJECT_NAME}

    ${CFG}
    ${DEFS}
    ${CONFIG}

    ${V_HEADERS}
    ${V_SOURCES}
    ${ZCM_TYPES}

    main.cpp
    )

target_link_libraries( ${PROJECT_NAME} ${V_LIBRARIES} -ldl )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================
