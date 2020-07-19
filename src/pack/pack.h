/*! \file pack.h
 * \brief Data package from multiple sensors.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#ifndef PACK_H
#define PACK_H

#include "defs.h"

#include "ZcmService.hpp"

//=======================================================================================
/*! \class Data
 * \brief ZCM message wrapper class.
 */
class Data : ZcmService
{
public:

    /*! \fn void operator =( const ZcmService& data );
     * \brief Convert ZcmService data to custom format.
     * \param[in] data Message data.
     */
    void operator =( const ZcmService& data );

    //-----------------------------------------------------------------------------------

    /*! \fn void clear();
     * \brief Clear data members.
     */
    void clear();

    //-----------------------------------------------------------------------------------

    /*! \fn const int64_t & timestamp() const;
     * \brief timestamp getter.
     * \return Saved timestamp.
     */
    const int64_t & timestamp() const;

    //-----------------------------------------------------------------------------------

private:

    //! \brief Raw data timestamp.
    int64_t _timestamp {0};

};
//=======================================================================================


//=======================================================================================
struct Pack
{
    Data data;

    // ... Add new data entry if you need fusion.

    //-----------------------------------------------------------------------------------

    void clear();

};
//=======================================================================================

#endif // PACK_H
