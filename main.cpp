#include "config.h"
#include "demo.h"
#include "handler.h"
#include "sender.h"
#include "messages.h"

#include "niias_arguments.h"
#include "vbyte_buffer_view.h"
#include "vbyte_buffer.h"
#include "vserial_port.h"
#include "vsignal.h"
#include "vcat.h"

#include <iostream>
#include <iomanip>

#include "LdConnectionFactory.h"
#include "LdDeviceFactory.h"
#include "LdPropertyIds.h"
#include "LdResultEchoes.h"
#include "LdSensorVu8.h"
#include "LdSpiFTDI.h"
#include "LdLjrRecorder.h"
#include "LdRecordPlayer.h"

//Modbus
#include "LdConnectionInfoModbus.h"
#include "LdLibModbusSerial.h"
#include "LdSensorOneModbus.h"
#include "LdSensorM16Modbus.h"
#include "LdSensorVu8Modbus.h"

//USB
#include "LdLibUsb.h"
#include "LdProtocolLeddartechUSB.h"

//CANBus
#include "LdCanKomodo.h"
#include "LdProtocolCan.h"
#include "LdConnectionUniversalCan.h"
#include "LdSensorM16Can.h"
#include "LdSensorVu8Can.h"

//Utils
#include "LtExceptions.h"
#include "LtKeyboardUtils.h"
#include "LtStringUtils.h"
#include "LtTimeUtils.h"

#include "LtDefines.h"

using namespace std;

//=======================================================================================
void connection( Handler& handler, LeddarDevice::LdSensor *aSensor, Config& config )
{
    try
    {
        Messages::changeConfiguration( aSensor, config );

        vdeb << "Start reading data.";
        aSensor->SetDataMask( LeddarDevice::LdSensor::DM_ALL );

        while( true )
        {
            auto average = average_echo( "Sensor " , aSensor );

            handler.send_data( average );

            LeddarUtils::LtTimeUtils::Wait( 10 );
        }

        aSensor->SetDataMask( LeddarDevice::LdSensor::DM_NONE );
    }

    catch( std::exception &e )
    {
        vdeb << "Exception: " << e.what();
    }

    aSensor->Disconnect();
}
//=======================================================================================


//=======================================================================================
int main( int argc, char **argv )
{
    niias::arguments nargs( argc, argv );

    Config config( nargs.config_name() );

//    Demo demo( config );

    if ( config.main.debug )
        vlog::clear_executers();
    vlog::set_shared_log ( nargs.full_app() + ".log",  1e6, 5 );

    vdeb << "Connection to Leddar Vu USB/Serial";

    LeddarConnection::LdConnectionInfo         *lConnectionInfo = nullptr;
    LeddarConnection::LdConnection             *lConnection = nullptr;
    LeddarDevice::LdSensor                     *lSensor = nullptr;

    Sender udp;
    Handler data_handler;

    data_handler.send_data.link( &udp, &Sender::on_some_signal );

    lConnectionInfo = LeddarConnection::LdLibModbusSerial::GetDevice( config.sensor.path,
                                                                      config.serial.baud_rate );

    if ( lConnectionInfo->GetDisplayName().empty() )
        throw verror << "Cannot connect to" << config.sensor.path;

    vdeb << " - " << lConnectionInfo->GetDisplayName() << " connected.";

    dynamic_cast< LeddarConnection::LdConnectionInfoModbus * >( lConnectionInfo )->
            SetModbusAddr( uint8_t ( config.serial.modbus_address ) );

    // Create the connection object
    lConnection = dynamic_cast< LeddarConnection::LdConnectionUniversal * >
            ( LeddarConnection::LdConnectionFactory::CreateConnection( lConnectionInfo ) );

    if ( !lConnection )
        throw verror << "Cannot connect to" << config.sensor.path;

    lSensor = LeddarDevice::LdDeviceFactory::CreateSensor( lConnection );

    if( lSensor != nullptr )
    {
        lSensor->GetConstants();
        lSensor->GetConfig();
    }

    if( lSensor )
        connection( data_handler, lSensor, config );

    if( lSensor )
    {
        lSensor->Disconnect();
        delete lSensor;
    }

    return EXIT_SUCCESS;
}
//=======================================================================================
