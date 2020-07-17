/*! \file view.h
 * \brief View class interface.
 *
 * Data PCL viewer.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef VIEW_H
#define VIEW_H

#include "config.h"

#include "vsignal.h"
#include "vthread.h"

#include <pcl/visualization/pcl_visualizer.h>

#include <string>

//=======================================================================================
/*! \class View
 * \brief Data PCL viewer.
 * \details ...
 */
class View
{
public:

    /*!
     * \brief constructor.
     * \param name Path to configuration file.
     * \details Initialize _plot PCL visualizer basic options.
    */
    View( const std::string name );

    //! \brief default destructor.
    ~View() = default;

    //-----------------------------------------------------------------------------------

private:

    pcl::visualization::PCLVisualizer _plot;

};
//=======================================================================================

#endif // VIEW_H
