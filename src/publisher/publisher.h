/*! \file publisher.h
 * \brief Publisher class interface.
 *
 * ZCM message publisher.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "config.h"

#include "vzcm.h"

#include "ZcmService.hpp"

//=======================================================================================
/*! \class Publisher
 * \brief ZCM message publisher class.
 * \details ...
 */
class Publisher
{
public:

    Publisher( const Config& conf );
    ~Publisher() = default;

    //-----------------------------------------------------------------------------------

private:

    //! \param _conf configuration parameters
    Config _conf;

    //! \param _zcm ZCM node
    vzcm _zcm;
};
//=======================================================================================

#endif // PUBLISHER_H
