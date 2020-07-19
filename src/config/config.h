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

#include "vsettings.h"
#include "vlog.h"

//=======================================================================================
/*! \class Config
 * \brief Configuration file parser class.
 */
class Config
{
public:

    /*!
     * \brief Config constructor.
     * \details Build default settings if cannot parse them from config.
     */
    Config();

    //! \brief Default Config deconstructor.
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
     * \param target  Inter Process Communications.
     * \param prefix  ZCM in channel prefix.
     * \param channel ZCM in channel name.
     * \param ch      Concatenated prefix and channel strings.
     * \param str     Struct name.
     */
    struct Receive
    {
        std::string target  { "ipc" };
        std::string prefix  {};
        std::string channel {};

        std::string ch {};
        std::string str { "receive" };

    } receive;

    //-----------------------------------------------------------------------------------

    /*! \struct Send
     * \param target  Inter Process Communications.
     * \param prefix  ZCM out channel prefix.
     * \param channel ZCM out channel name.
     * \param ch      Concatenated prefix and channel strings.
     * \param str     Struct name.
     */
    struct Send
    {
        std::string target  { "ipc" };
        std::string prefix  {};
        std::string channel {};

        std::string ch {};
        std::string str { "send" };

    } send;

    //-----------------------------------------------------------------------------------

    /*! \struct Logs
     * \param need_trace   Flag if need log service messages to file.
     * \param need_shared  Flag if need write all logging levels to one file.
     * \param shared_name  Shared log filename.
     * \param need_leveled Flag if need write each level of logging to its own file.
     * \param leveled_path Leveled logs path.
     * \param file_sizes   Log max size in Kb.
     * \param rotates      Max logs count.
     * \param str          Struct name.
     */
    struct Logs
    {
        bool need_trace = true;

        bool need_shared = true;
        std::string shared_name = "$$FULL_APP.log";

        bool need_leveled = true;
        std::string leveled_path = "$$APP_PATH/logs";

        uint file_sizes = 1e6;
        uint rotates {3};

        /*! \fn void setup();
         * \brief Starts log data.
         * \details Check Logs flags and run logging if need.
         */
        void setup();

        std::string str { "logs" };

    } logs;

    //-----------------------------------------------------------------------------------

    /*! \fn void capture( const vsettings& data );
     * \brief Fill internal schema.
     * \param[in] data Third-party settings.
     */
    void capture( const vsettings& data );

    /*! \fn static vsettings by_default();
     * \brief Generates config with default settings.
     * \return Default settings.
     */
    static vsettings by_default();

    //-----------------------------------------------------------------------------------

private:

    //! \brief Container of configuration file groups and subgroups.
    vsettings::schema _schema;

    //-----------------------------------------------------------------------------------

    /*! \fn void _fill_ch();
     * \brief Fill receive/send channels fullnames.
     */
    void _fill_ch();

};
//=======================================================================================

#endif // CONFIG_H
