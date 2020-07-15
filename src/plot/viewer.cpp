/*! \file viewer.cpp
 * \brief Viewer class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "viewer.h"

//=======================================================================================
Viewer::Viewer( const std::string name )
{
    _viewer.setWindowName( name );
    _viewer.addCoordinateSystem( 1.0, "cloud", 0 );
    _viewer.setBackgroundColor( 0., 0., 0., 0 );
}
//=======================================================================================
