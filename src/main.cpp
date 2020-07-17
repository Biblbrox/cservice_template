/*! \file main.cpp
 * \brief Entry app file.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 *
 * Details.
 *
 */

//=======================================================================================

#include "subscribe.h"
#include "publish.h"
#include "config.h"
#include "core.h"
#ifdef GUI
#include "view.h"
#endif

#include "niias_arguments.h"

#include "vapplication.h"
#include "vthread.h"
#include "vlog.h"

#include "vzcm.h"

#include <iostream>

//=======================================================================================
/*! \fn int main( int argc, char **argv )
 * \brief Entry point.
 *
 * Execution of the program starts here.
 *
 * \param argc Number of arguments.
 * \param argv List of arguments.
 *
 * \return App exit status.
 */
int main( int argc, char **argv )
{
    niias::arguments nargs( argc, argv );

    Config config( nargs.config_name() );

    //-----------------------------------------------------------------------------------

    if ( config.main.debug )
        vlog::clear_executers();
    vlog::set_shared_log ( nargs.full_app() + ".log",  1e6, 5 );

    //-----------------------------------------------------------------------------------

    Subscribe subscriber( config );
    Publish publisher( config );
    Core core( config );

    subscriber.received.link( &core, &Core::run );

    // Custom link Core --> Publish

    //-----------------------------------------------------------------------------------

#ifdef GUI
    vthread thread;
    thread.invoke( [&]
    {
        View viewer( nargs.app_name() );
        viewer.run();
    } );
#endif

    //-----------------------------------------------------------------------------------

    vapplication::poll();

    return EXIT_SUCCESS;
}
//=======================================================================================
