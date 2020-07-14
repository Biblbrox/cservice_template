/*! \file subscriber.cpp
 * \brief Subscriber class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

#include "subscriber.h"

//=======================================================================================
Subscriber::Subscriber( const Config& conf )
    : _conf ( std::move( conf )   )
    , _zcm  ( conf.receive.target )
{
    _zcm.subscribe<ZcmLivoxScan>( conf.receive.ch(),
                                  [ this ]( const ZcmLivoxScan& msg )
    {
        _data = msg.service;
    } );
}
//=======================================================================================
