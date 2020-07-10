/*! \file main.cpp
 * \brief Entry app file.
 *
 * \authors Dmitrii Leliuhin
 *
 * Details.
 *
 */

#include "config.h"

#include "niias_arguments.h"

#include "vapplication.h"
#include "vlog.h"

#include <iostream>

using namespace std;

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
    vapplication vapp;
    niias::arguments nargs( argc, argv );

    Config config( nargs.config_name() );

    if ( config.main.debug )
        vlog::clear_executers();
    vlog::set_shared_log ( nargs.full_app() + ".log",  1e6, 5 );

    return EXIT_SUCCESS;
}
//=======================================================================================
