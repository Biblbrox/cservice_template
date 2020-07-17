/*! \file view.cpp
 * \brief View class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "view.h"

using namespace pcl::visualization;

//=======================================================================================
View::View( const std::string name )
{
    _plot.setWindowName( name );
    _plot.setSize( 1600, 900 );
    _plot.addCoordinateSystem( 1.0, "cloud", 0 );
    _plot.setBackgroundColor( 0., 0., 0., 0 );

    _thread.invoke( this, &View::run );
}
//=======================================================================================
View::~View()
{
    _thread.join();
}
//=======================================================================================


//=======================================================================================
void View::run()
{
    while ( !_plot.wasStopped() )
        _plot.spin();
}
//=======================================================================================
