/*! \file publisher.cpp
 * \brief Publisher class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "publisher.h"

#include "vtime_point.h"

//=======================================================================================
Publisher::Publisher( const Config& conf )
    : _conf ( std::move( conf ) )
    , _zcm  ( conf.send.target  )
{
    ZcmService msg;
    msg.u_timestamp = vtime_point::now().microseconds().count();

    auto now = vtime_point::now().microseconds().count();
    msg.processing_time = int32_t( now - msg.u_timestamp );

    _zcm.publish( conf.send.ch(), &msg );
}
//=======================================================================================
