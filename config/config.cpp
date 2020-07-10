#include "config.h"

//=======================================================================================
Config::Config( const std::string& fname )
{
    _build();

    if ( !fname.empty() )
        _settings.from_ini_file( fname );

    {
        auto group = _settings.subgroup( main.str );

        main.pid_path = group.get( "pid_path" );
        main.type = group.get( "type" );
        main.debug = _stob( group.get( "debug" ) );
    }

    //    "******************** LeddarExample ********************";
    //    "1 - Connect to LeddarVu USB/Serial";
    //    "2 - Connect to LeddarVu USB/Serial (Modbus protocol)";
    //    "3 - Connect to LeddarVu SPI";
    //    "4 - Connect to LeddarVu CANBus (protocol SPI)";
    //    "5 - Connect to LeddarVu CANBus (protocol CAN)";
    //    "6 - Connect to M16 USB";
    //    "7 - Connect to M16 Modbus";
    //    "8 - Connect to M16 CANBus";
    //    "9 - Connect to LeddarOne Modbus";
    //    "10 - Read recording";
    //    "0 - Exit";
    //    "Select: ";

    if ( main.type == "serial" )
        main.choise = 1;

    {
        auto group = _settings.subgroup( calib.str );

        calib.distance = std::stof( group.get( "distance" ) );
        calib.deviation = std::stof( group.get( "deviation" ) );
    }

    {
        auto group = _settings.subgroup( send.str );

        send.ip = group.get( "ip" );
        send.port = std::stoi( group.get( "port" ) );
        send.frequency = std::stoi( group.get( "frequency" ) ) * 1e6;
    }

    {
        auto group = _settings.subgroup( sensor.str );

        sensor.path = group.get( "path" );
        sensor.name = group.get( "name" );
        sensor.segment_enable = group.get( "segment_enable" );

        sensor.threshold_offset = std::stof( group.get( "threshold_offset" ) );

        sensor.led_intensity = std::stoi( group.get( "led_intensity" ) );
        sensor.accumulation_exponent = std::stoi( group.get( "accumulation_exponent" ) );
        sensor.oversampling_exponent = std::stoi( group.get( "oversampling_exponent" ) );
        sensor.base_point_count = std::stoi( group.get( "base_point_count" ) );
        sensor.temperature_compensation = std::stoi( group.get( "temperature_compensation" ) );
        sensor.smoothing = std::stoi( group.get( "smoothing" ) );
        sensor.auto_led_power_enable = std::stoi( group.get( "auto_led_power_enable" ) );
        sensor.change_delay_channel = std::stoi( group.get( "change_delay_channel" ) );
        sensor.change_delay_frame = std::stoi( group.get( "change_delay_frame" ) );
        sensor.carrier_options = std::stoi( group.get( "carrier_options" ) );

        sensor.crosstalk_removal_enable = _stob( group.get( "crosstalk_removal_enable" ) );
        sensor.static_noise_removal_enable = _stob( group.get( "static_noise_removal_enable" ) );
        sensor.saturation_compensation_enable = _stob( group.get( "saturation_compensation_enable" ) );
        sensor.smoothing_enable = _stob( group.get( "smoothing_enable" ) );
        sensor.overshoot_management_enable = _stob( group.get( "overshoot_management_enable" ) );
        sensor.crosstalk_echo_removal_enable = _stob( group.get( "crosstalk_echo_removal_enable" ) );
        sensor.demerging_enable = _stob( group.get( "demerging_enable" ) );
    }

    {
        auto group = _settings.subgroup( offset.str );

        offset.x = std::stod( group.get( "x" ) );
        offset.y = std::stod( group.get( "y" ) );
        offset.z = std::stod( group.get( "z" ) );
        offset.roll = std::stod( group.get( "roll" ) );
        offset.pitch = std::stod( group.get( "pitch" ) );
        offset.yaw = std::stod( group.get( "yaw" ) );
    }

    {
        auto group = _settings.subgroup( serial.str );

        serial.distance_resolution = group.get( "distance_resolution" );

        serial.baud_rate = std::stoi( group.get( "baud_rate" ) );
        serial.data_bit = std::stoi( group.get( "data_bit" ) );
        serial.parity = std::stoi( group.get( "parity" ) );
        serial.stop_bit = std::stoi( group.get( "stop_bit" ) );
        serial.modbus_address = std::stoi( group.get( "modbus_address" ) );
        serial.maximum_echoes = std::stoi( group.get( "maximum_echoes" ) );
        serial.flow_control_val = std::stoi( group.get( "flow_control_val" ) );
        serial.logical_port_number = std::stoi( group.get( "logical_port_number" ) );
    }

    {
        auto group = _settings.subgroup( can.str );

        can.distance_resolution = group.get( "distance_resolution" );

        can.baud_rate = std::stoi( group.get( "baud_rate" ) );
        can.base_tx_id = std::stoi( group.get( "base_tx_id" ) );
        can.base_rx_id = std::stoi( group.get( "base_rx_id" ) );
        can.frame_format = std::stoi( group.get( "frame_format" ) );
        can.inter_message_delay = std::stoi( group.get( "inter_message_delay" ) );
        can.inter_cycle_delay = std::stoi( group.get( "inter_cycle_delay" ) );
        can.maximum_echoes = std::stoi( group.get( "maximum_echoes" ) );
        can.logical_port = std::stoi( group.get( "logical_port" ) );
    }
}
//=======================================================================================
Config::~Config()
{

}
//=======================================================================================


//=======================================================================================
void Config::_build()
{
    _settings.subgroup( this->main.str ).set( "pid_path", "/tmp/niias" );
    _settings.subgroup( this->main.str ).set( "type", "serial" );
    _settings.subgroup( this->main.str ).set( "debug", false );

    _settings.subgroup( this->calib.str ).set( "distance", 2.0 );
    _settings.subgroup( this->calib.str ).set( "deviation", 0.2 );

    _settings.subgroup( this->send.str ).set( "ip", "127.0.0.1" );
    _settings.subgroup( this->send.str ).set( "port", 9000 );
    _settings.subgroup( this->send.str ).set( "frequency", 1 );

    _settings.subgroup( this->sensor.str ).set( "path", "ttyUSB0" );
    _settings.subgroup( this->sensor.str ).set( "name",  "AK15068" );
    _settings.subgroup( this->sensor.str ).set( "led_intensity", 100 );
    _settings.subgroup( this->sensor.str ).set( "accumulation_exponent", 3 );
    _settings.subgroup( this->sensor.str ).set( "oversampling_exponent", 3 );
    _settings.subgroup( this->sensor.str ).set( "base_point_count", 18 );
    _settings.subgroup( this->sensor.str ).set( "static_noise_removal_enable", true );
    _settings.subgroup( this->sensor.str ).set( "temperature_compensation", 1 );
    _settings.subgroup( this->sensor.str ).set( "smoothing", 0 );
    _settings.subgroup( this->sensor.str ).set( "smoothing_enable", true );
    _settings.subgroup( this->sensor.str ).set( "threshold_offset", 0.00 );
    _settings.subgroup( this->sensor.str ).set( "segment_enable", "111111111" );
    _settings.subgroup( this->sensor.str ).set( "saturation_compensation_enable", true );
    _settings.subgroup( this->sensor.str ).set( "overshoot_management_enable", true );
    _settings.subgroup( this->sensor.str ).set( "auto_led_power_enable", 1 );
    _settings.subgroup( this->sensor.str ).set( "change_delay_channel", 1 );
    _settings.subgroup( this->sensor.str ).set( "change_delay_frame", 16 );
    _settings.subgroup( this->sensor.str ).set( "crosstalk_removal_enable", true );
    _settings.subgroup( this->sensor.str ).set( "crosstalk_echo_removal_enable", true );
    _settings.subgroup( this->sensor.str ).set( "demerging_enable", false );
    _settings.subgroup( this->sensor.str ).set( "carrier_options", 0 );

    _settings.subgroup( this->offset.str ).set( "x", 0.000 );
    _settings.subgroup( this->offset.str ).set( "y", 0.000 );
    _settings.subgroup( this->offset.str ).set( "z", 0.000 );
    _settings.subgroup( this->offset.str ).set( "roll", 0.000 );
    _settings.subgroup( this->offset.str ).set( "pitch", 0.000 );
    _settings.subgroup( this->offset.str ).set( "yaw", 0.000 );

    _settings.subgroup( this->serial.str ).set( "baud_rate",  115200 );
    _settings.subgroup( this->serial.str ).set( "data_bit", 8 );
    _settings.subgroup( this->serial.str ).set( "parity", 0 );
    _settings.subgroup( this->serial.str ).set( "stop_bit", 1 );
    _settings.subgroup( this->serial.str ).set( "modbus_address", 1 );
    _settings.subgroup( this->serial.str ).set( "maximum_echoes", 40 );
    _settings.subgroup( this->serial.str ).set( "flow_control_val", 0 );
    _settings.subgroup( this->serial.str ).set( "logical_port_number", 1 );
    _settings.subgroup( this->serial.str ).set( "distance_resolution", "cm" );

    _settings.subgroup( this->can.str ).set( "baud_rate", 1000000 );
    _settings.subgroup( this->can.str ).set( "base_tx_id", 1872 );
    _settings.subgroup( this->can.str ).set( "base_rx_id", 1856 );
    _settings.subgroup( this->can.str ).set( "frame_format", 11 );
    _settings.subgroup( this->can.str ).set( "inter_message_delay", 0 );
    _settings.subgroup( this->can.str ).set( "inter_cycle_delay", 0 );
    _settings.subgroup( this->can.str ).set( "maximum_echoes", 96 );
    _settings.subgroup( this->can.str ).set( "logical_port", 0 );
    _settings.subgroup( this->can.str ).set( "distance_resolution", "cm" );
}
//=======================================================================================
bool Config::_stob( std::string str )
{
    return ( str == "true" ) ? true : false;
}
//=======================================================================================
