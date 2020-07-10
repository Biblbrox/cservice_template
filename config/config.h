#ifndef CONFIG_H
#define CONFIG_H

#include "vlog.h"
#include "vsettings.h"
#include "vsocket_address.h"
#include "vterminal_options.h"

//=======================================================================================
class Config
{
public:

    Config( const std::string& fname = {} );
    ~Config();

    //-----------------------------------------------------------------------------------

    struct Main
    {
        std::string pid_path;
        std::string type;
        uint32_t choise = 0;

        bool debug;

        std::string str = "main";

    } main;

    //-----------------------------------------------------------------------------------

    struct Calib
    {
        float distance;
        float deviation;

        std::string str = "calibration";

    } calib;

    //-----------------------------------------------------------------------------------

    struct Send
    {
        std::string ip;
        int port;

        int frequency;

        std::string str = "send";

    } send;

    //-----------------------------------------------------------------------------------

    struct Sensor
    {
        std::string path;
        std::string name;
        std::string segment_enable;

        float threshold_offset;

        int led_intensity;
        int accumulation_exponent;
        int oversampling_exponent;
        int base_point_count;
        int temperature_compensation;
        int smoothing;
        int auto_led_power_enable;
        int change_delay_channel;
        int change_delay_frame;
        int carrier_options;

        bool crosstalk_removal_enable;
        bool static_noise_removal_enable;
        bool saturation_compensation_enable;
        bool smoothing_enable;
        bool overshoot_management_enable;
        bool crosstalk_echo_removal_enable;
        bool demerging_enable;

        std::string str = "sensor";

    } sensor;

    //-----------------------------------------------------------------------------------

    struct Offset
    {
        double x;
        double y;
        double z;
        double roll;
        double pitch;
        double yaw;

        std::string str = "offset";

    } offset;

    //-----------------------------------------------------------------------------------

    struct Serial
    {
        std::string distance_resolution;

        int baud_rate;
        int data_bit;
        int parity;
        int stop_bit;
        int modbus_address;
        int maximum_echoes;
        int flow_control_val;
        int logical_port_number;

        std::string str = "serial";

    } serial;

    //-----------------------------------------------------------------------------------

    struct Can
    {
        std::string distance_resolution;

        int baud_rate;
        int base_tx_id;
        int base_rx_id;
        int frame_format;
        int inter_message_delay;
        int inter_cycle_delay;
        int maximum_echoes;
        int logical_port;

        std::string str = "can";

    } can;

    //-----------------------------------------------------------------------------------

private:

    vsettings _settings;

    vterminal_options _serial_options;

    void _build();

    bool _stob( std::string str );
};
//=======================================================================================

#endif // CONFIG_H
