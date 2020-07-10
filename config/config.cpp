/*! \file config.cpp
 * \brief Config class implementation.
 *
 * \authors Dmitrii Leliuhin
*/

//=======================================================================================

#include "config.h"

#include "vlog.h"

using namespace std;

//=======================================================================================
Config::Config( const std::string& fname )
{
    _build();

    if ( !fname.empty() )
        _settings.from_ini_file( fname );

    {
        auto group = _settings.subgroup( main.str );

        main.debug = _stob( group.get( "debug" ) );
    }

    {
        auto group = _settings.subgroup( receive.str );

        receive.target  = group.get( "target"  );
        receive.prefix  = group.get( "prefix"  );
        receive.channel = group.get( "channel" );
    }

    {
        auto group = _settings.subgroup( send.str );

        send.target  = group.get( "target"  );
        send.prefix  = group.get( "prefix"  );
        send.channel = group.get( "channel" );
    }
}
//=======================================================================================


//=======================================================================================
void Config::_build()
{
    _settings.subgroup( this->main.str ).set( "debug", main.debug );

    _settings.subgroup( this->receive.str ).set( "target",  receive.target );
    _settings.subgroup( this->receive.str ).set( "prefix",  receive.prefix );
    _settings.subgroup( this->receive.str ).set( "channel", receive.channel );

    _settings.subgroup( this->send.str ).set( "target",  send.target );
    _settings.subgroup( this->send.str ).set( "prefix",  send.prefix );
    _settings.subgroup( this->send.str ).set( "channel", send.channel );
}
//=======================================================================================
bool Config::_stob( const std::string str )
{
    if ( str == "true" ) return true;
    if ( str == "false" ) return false;

    return false;
}
//=======================================================================================
