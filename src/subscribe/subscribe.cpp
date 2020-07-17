/*! \file subscribe.cpp
 * \brief Subscribe class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#include "subscribe.h"

#include "vtime_point.h"

//=======================================================================================
Subscribe::Subscribe( const Config& conf )
    : _conf ( std::move( conf )   )
    , _zcm  ( conf.receive.target )
{
    _pack.clear();

    _zcm.subscribe<ZcmService>( conf.receive.ch, [ this ]( const ZcmService& msg )
    {
        _pack.data = msg;

        received( _pack );
    } );
}
//=======================================================================================
