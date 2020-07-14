/*! \file publish.cpp
 * \brief Publish class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "publish.h"

#include "vtime_point.h"

//=======================================================================================
Publish::Publish( const Config& conf )
    : _conf ( std::move( conf ) )
    , _zcm  ( conf.send.target  )
{}
//=======================================================================================


//=======================================================================================
void Publish::send( const ZcmService& data )
{
    ZcmService msg = std::move( data );
    msg.u_timestamp = vtime_point::now().microseconds().count();

    auto now = vtime_point::now().microseconds().count();
    msg.processing_time = int32_t( now - msg.u_timestamp );

    _zcm.publish( _conf.send.ch(), &msg );
}
//=======================================================================================
