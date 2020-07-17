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

#include "vapplication.h"
#include "vsignal.h"
#include "vthread.h"

#include <pcl/visualization/pcl_visualizer.h>

#include <string>

//=======================================================================================
/*! \class View
 * \brief Data PCL viewer.
 * \details Interconnects with the rest of the application classes to render results.
 */
class View
{
public:

    /*! \brief constructor.
     * \param[in] name Path to configuration file.
     * \details Initialize _plot PCL visualizer basic options.
     */
    View( const std::string& name = {} );

    /*! \brief default destructor.
     * \details Close plot widget and stops the application.
     */
    ~View();

    //-----------------------------------------------------------------------------------

    /*! \fn void run();
     * \brief run Starts viewer loop.
     */
    void run();

    //-----------------------------------------------------------------------------------

private:

    /*! \var _plot
     * \brief Data visualization widget reference.
     */
    pcl::visualization::PCLVisualizer _plot;

};
//=======================================================================================

#endif // VIEW_H
