/*! \file main.cpp
 * \brief Entry app file.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 *
 * Details.
 *
 */

#include "config.h"
#include "subscribe.h"
#include "publish.h"
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
//    vapplication vapp;
    niias::arguments nargs( argc, argv );

    Config config( nargs.config_name() );

    //-----------------------------------------------------------------------------------

    if ( config.main.debug )
        vlog::clear_executers();
    vlog::set_shared_log ( nargs.full_app() + ".log",  1e6, 5 );

    //-----------------------------------------------------------------------------------

    Subscribe subscriber( config );
    Publish publisher( config );

    subscriber.received.link( &publisher, &Publish::send );

    //-----------------------------------------------------------------------------------

#ifdef GUI
    View viewer( nargs.app_name() );
#endif

    //-----------------------------------------------------------------------------------

//    vapp.poll();

    return EXIT_SUCCESS;
}
//=======================================================================================
