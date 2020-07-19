/*! \file core.h
 * \brief Core class interface.
 *
 * Class for algorithmic message processing.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#ifndef CORE_H
#define CORE_H

#include "config.h"
#include "pack.h"

#include "vsignal.h"

//=======================================================================================
/*! \class Core
 * \brief Cascading data processing
 */
class Core
{
public:

    /*!
     * \brief constructor.
     * \param[in] fname Path to configuration file.
     * \details Initialize _zcm node.
     */
    Core( const Config& conf );

    //! \brief default destructor.
    ~Core() = default;

    //-----------------------------------------------------------------------------------

    /*! \fn void run( const Pack& pack );
     * \brief Run data processing.
     * \param[in] rec raw timestamp.
     */
    void run( const Pack& pack );

    //-----------------------------------------------------------------------------------

    /*!
     * \brief emit signal if pack processed.
     * \param int64_t Raw data timestamp.
     * \param ZcmService Service message.
     */
    vsignal<int64_t, ZcmService> processed;

    //-----------------------------------------------------------------------------------

private:

    //! \brief Configuration parameters.
    Config _conf;

};
//=======================================================================================

#endif // CORE_H
