#========================================================================================

project( tests )

#========================================================================================

cmake_minimum_required( VERSION 3.10 )

#========================================================================================

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage" )

#========================================================================================

set ( GTEST_INCLUDED TRUE )
find_library( GTEST_LIBRARY NAMES libgtest.a PATHS ${EXT_LIBS_PATH} )
set( ${PROJECT_NAME} -lgtest )

message( "${CMAKE_CURRENT_SOURCE_DIR}/../.." )

add_directory( ${CMAKE_CURRENT_SOURCE_DIR}/.. )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================
