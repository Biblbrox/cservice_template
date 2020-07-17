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
 */
class Config
{
public:

    /*!
     * \brief Config constructor.
     * \param fname Path to configuration file.
     * \details Build default settings if cannot parse them from config.
     */
    Config( const std::string& fname = {} );

    //! \brief Default Config deconstructor.
    ~Config() = default;

    //-----------------------------------------------------------------------------------

    /*! \struct Main
     * \var debug Flag if need trace service info to log file.
     * \var str Struct name.
     */
    struct Main
    {
        bool debug { false };

        std::string str { "main" };

    } main;

    //-----------------------------------------------------------------------------------

    /*! \struct Receive
     * \var target Inter Process Communications.
     * \var prefix ZCM in channel prefix.
     * \var channel ZCM in channel name.
     * \var str Struct name.
     */
    struct Receive
    {
        std::string target  { "ipc" };
        std::string prefix  {};
        std::string channel {};

        /*! \fn std::string ch() const
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
     * \var target Inter Process Communications.
     * \var prefix ZCM out channel prefix.
     * \var channel ZCM out channel name.
     * \var str Struct name.
     */
    struct Send
    {
        std::string target  { "ipc" };
        std::string prefix  {};
        std::string channel {};

        /*! \fn std::string ch() const
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

    //! \var _settings Container of configuration file groups and subgroups.
    vsettings _settings;

    //-----------------------------------------------------------------------------------

    /*! \fn void _build()
     * \brief Set the default parameters to _settings.
     */
    void _build();

    /*! \fn bool _stob( std::string str )
     * \brief Convert string value to bool.
     */
    bool _stob( const std::string& str );

};
//=======================================================================================

#endif // CONFIG_H
