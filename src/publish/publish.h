/*! \file publish.h
 * \brief Publish class interface.
 *
 * ZCM message publish.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#pragma once

#include "config.h"

#include "vsignal.h"

#include "vzcm.h"

#include "ZcmService.hpp"

//=======================================================================================
/*! \class Publish
 * \brief ZCM message publisher class.
 */
class Publish
{
public:

    /*!
     * \param[in] conf Configuration settings.
     * \details Initialize _zcm node.
     */
    Publish( const Config& conf = {} );

    //! \brief default destructor.
    ~Publish() = default;

    //-----------------------------------------------------------------------------------

    /*! \fn void send( const int64_t& rec, const ZcmService& data );
     * \brief send processed data to ZCM.
     * \param[in] rec raw timestamp.
     * \param[in] data from ZCM bus.
     */
    void send( const int64_t& rec, const ZcmService& data );

    //-----------------------------------------------------------------------------------

private:

    //! \brief Configuration parameters.
    Config _conf;

    //! \brief ZCM node.
    vzcm _zcm;

};
//=======================================================================================
