/*! \file view.cpp
 * \brief View class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "view.h"

#include "vlog.h"

using namespace pcl::visualization;

//=======================================================================================
View::View( const std::string& name )
{
    _plot.setWindowName( name );
    _plot.setSize( 1600, 900 );
    _plot.addCoordinateSystem( 1.0, "cloud", 0 );
    _plot.setBackgroundColor( 0., 0., 0., 0 );
}
//=======================================================================================
View::~View()
{
    _plot.close();
    vapplication::stop();
}
//=======================================================================================


//=======================================================================================
void View::run()
{
    _plot.spin();
}
//=======================================================================================
