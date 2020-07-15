/*! \file viewer.h
 * \brief Viewer class interface.
 *
 * Data PCL viewer.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef PLOT_H
#define PLOT_H

#include "config.h"

#include "vsignal.h"

#include <pcl/visualization/pcl_visualizer.h>

#include <string>

//=======================================================================================
/*! \class Viewer
 * \brief Data PCL viewer.
 * \details ...
 */
class Viewer
{
public:

    /*!
     * \brief constructor.
     * \param name Path to configuration file.
     * \details Initialize _zcm node
    */
    Viewer( const std::string name );

    //! \brief default destructor.
    ~Viewer() = default;

    //-----------------------------------------------------------------------------------

private:

    pcl::visualization::PCLVisualizer _viewer;

};
//=======================================================================================

#endif // PLOT_H
