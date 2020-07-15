/*! \file subscribe.h
 * \brief Subscribe class interface.
 *
 * ZCM message subscriber.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include "config.h"

#include "vzcm.h"
#include "vsignal.h"

#include "ZcmService.hpp"
#include "ZcmLivoxScan.hpp"

//=======================================================================================
/*! \class Subscribe
 * \brief ZCM message subscriber class.
 * \details ...
 */
class Subscribe
{
public:

    /*!
     * \brief constructor.
     * \param fname Path to configuration file.
     * \details Initialize _zcm node
    */
    Subscribe( const Config& conf );

    //! \brief default destructor.
    ~Subscribe() = default;

    //-----------------------------------------------------------------------------------

    //! \brief received emit signal if ZCM message received
    vsignal<int64_t, ZcmService> received;

    //-----------------------------------------------------------------------------------

private:

    //! \param _conf configuration parameters
    Config _conf;

    //! \param _zcm ZCM node
    vzcm _zcm;

};
//=======================================================================================

#endif // SUBSCRIBER_H
