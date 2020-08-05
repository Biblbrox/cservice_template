/*! \file publish.cpp
 * \brief Publish class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#include "publish.h"

#include "vlog.h"
#include "vtime_point.h"

//=======================================================================================
Publish::Publish( const Config& conf )
    : _conf ( conf              )
    , _zcm  ( conf.send.target  )
{}
//=======================================================================================


//=======================================================================================
void Publish::send( const int64_t& rec, const ZcmService& data )
{
    ZcmService msg = data;
    msg.u_timestamp = data.u_timestamp;
    msg.processing_time = int32_t( vtime_point::now().microseconds().count() - rec );

    _zcm.publish( _conf.send.channel.full, msg );
}
//=======================================================================================
