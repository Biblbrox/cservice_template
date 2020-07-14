/*! \file config.h
 * \brief Config class interface.
 *
 * Configuration file parser.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
*/

//=======================================================================================

#ifndef CONFIG_H
#define CONFIG_H

#include "vcat.h"
#include "vsettings.h"

//=======================================================================================
/*! \class Config
 * \brief Configuration file parser class.
 * \details ...
 */
class Config
{
public:

    /*!
     * \brief Config constructor.
     * \param fname Path to configuration file.
    */
    Config( const std::string& fname = {} );

    /*!
     * \brief Default Config deconstructor.
    */
    ~Config() = default;

    //-----------------------------------------------------------------------------------

    /*! \struct Main
     * \param debug Flag if need trace service info to log file.
     * \param str Struct name.
    */
    struct Main
    {
        bool debug { false };

        std::string str { "main" };

    } main;

    //-----------------------------------------------------------------------------------

    /*! \struct Receive
     * \param target Inter Process Communications.
     * \param prefix ZCM in channel prefix.
     * \param channel ZCM in channel name.
     * \param str Struct name.
    */
    struct Receive
    {
        std::string target  { "ipc"     };
        std::string prefix  { "In"      };
        std::string channel { "Channel" };

        /*!
         * \fn std::string ch() const
         * \return Concatenated prefix and channel strings.
        */
        std::string ch() const
        {
            return vcat( prefix, channel );
        }

        std::string str { "receive" };

    } receive;

    //-----------------------------------------------------------------------------------

    /*! \struct Send
     * \param target Inter Process Communications.
     * \param prefix ZCM out channel prefix.
     * \param channel ZCM out channel name.
     * \param str Struct name.
    */
    struct Send
    {
        std::string target  { "ipc"     };
        std::string prefix  { "In"      };
        std::string channel { "Channel" };

        /*!
         * \fn std::string ch() const
         * \return Concatenated prefix and channell strings.
        */
        std::string ch() const
        {
            return vcat( prefix, channel );
        }

        std::string str { "send" };

    } send;

    //-----------------------------------------------------------------------------------

private:

    //! \param _settings Container of configuration file groups and subgroups.
    vsettings _settings;

    //-----------------------------------------------------------------------------------

    /*! \fn void _build()
     * \brief Set the default parameters to _settings.
    */
    void _build();

    /*! \fn bool _stob( std::string str )
     * \brief Convert string value to bool.
    */
    bool _stob( std::string str );

};
//=======================================================================================

#endif // CONFIG_H
