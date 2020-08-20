/*! \file new_class.h
 * \brief NewClass class interface.
 *
 * Class description.
 *
 * \authors dmitrii
 * \date August 2020
 */

//=======================================================================================

#pragma once

#include "vsignal.h"

//=======================================================================================
/*! \class NewClass
 * \brief Some briefing
 */
class NewClass
{
public:

//! \brief default constructor.    
    NewClass() = default;

    //! \brief default destructor.
    ~NewClass() = default;

    //-----------------------------------------------------------------------------------

    /*! \brief Emitter.
     * \param Your parameter description.
     */
    vsignal</*Your parameter.*/> emit;

    //-----------------------------------------------------------------------------------

private:

    //! List of private variables.

};
//=======================================================================================
