/*! \file publish.h
 * \brief Publish class interface.
 *
 * ZCM message publish.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#ifndef PUBLISH_H
#define PUBLISH_H

#include "config.h"

#include "vzcm.h"
#include "vsignal.h"

#include "ZcmService.hpp"

//=======================================================================================
/*! \class Publish
 * \brief ZCM message publisher class.
 * \details ...
 */
class Publish
{
public:

    /*!
     * \brief constructor.
     * \param[in] fname Path to configuration file.
     * \details Initialize _zcm node.
     */
    Publish( const Config& conf );

    //! \brief default destructor.
    ~Publish() = default;

    //-----------------------------------------------------------------------------------

    /*! \fn void send( const int64_t rec, const ZcmService& data );
     * \brief send processed data to ZCM.
     * \param[in] rec raw timestamp.
     * \param[in] data from ZCM bus.
     */
    void send( const int64_t rec, const ZcmService& data );

    //-----------------------------------------------------------------------------------

private:

    //! \var _conf configuration parameters
    Config _conf;

    //! \var _zcm ZCM node
    vzcm _zcm;

};
//=======================================================================================

#endif // PUBLISH_H
