/*! \file subscriber.h
 * \brief Subscriber class interface.
 *
 * ZCM message subscriber.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "config.h"

#include "vzcm.h"

#include "ZcmService.hpp"
#include "ZcmLivoxScan.hpp"

//=======================================================================================
/*! \class Subscriber
 * \brief ZCM message subscriber class.
 * \details ...
 */
class Subscriber
{
public:

    Subscriber( const Config& conf );
    ~Subscriber() = default;

    //-----------------------------------------------------------------------------------

private:

    //! \param _conf configuration parameters
    Config _conf;

    //! \param _zcm ZCM node
    vzcm _zcm;

    //! \param _zcm ZCM received messages
    ZcmService _data;
};
//=======================================================================================

#endif // SUBSCRIBER_H
