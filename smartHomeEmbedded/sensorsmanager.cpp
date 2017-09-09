#include "sensorsmanager.h"
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#include <QThread>


#define MAX_TIMINGS	85
#define DHT_PIN		3	/* GPIO-22 */

int data[5] = { 0, 0, 0, 0, 0 };

sensorsManager::sensorsManager(QObject *parent) : QObject(parent)
{
    wiringPiSetup();
}

void sensorsManager::startDHTSensorThread()
{

}


void sensorsManager::readDHT22Data()
{
    uint8_t laststate	= HIGH;
    uint8_t counter		= 0;
    uint8_t j			= 0, i;

    data[0] = data[1] = data[2] = data[3] = data[4] = 0;

    /* pull pin down for 18 milliseconds */
    pinMode( DHT_PIN, OUTPUT );
    digitalWrite( DHT_PIN, LOW );
    delay( 18 );

    /* prepare to read the pin */
    pinMode( DHT_PIN, INPUT );

    /* detect change and read data */
    for ( i = 0; i < MAX_TIMINGS; i++ )
    {
        counter = 0;
        while ( digitalRead( DHT_PIN ) == laststate )
        {
            counter++;
            delayMicroseconds( 1 );
            if ( counter == 255 )
            {
                break;
            }
        }
        laststate = digitalRead( DHT_PIN );

        if ( counter == 255 )
            break;

        /* ignore first 3 transitions */
        if ( (i >= 4) && (i % 2 == 0) )
        {
            /* shove each bit into the storage bytes */
            data[j / 8] <<= 1;
            if ( counter > 16 )
                data[j / 8] |= 1;
            j++;
        }
    }

    /*
     * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
     * print it out if data is good
     */
    if ( (j >= 40) &&
         (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
    {
        float humidity = (float)((data[0] << 8) + data[1]) / 10;
        if ( humidity > 100 )
        {
            humidity = data[0];	// for DHT11
        }
        float temperatureInCelsius = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
        if ( temperatureInCelsius > 125 )
        {
            temperatureInCelsius = data[2];	// for DHT11
        }
        if ( data[2] & 0x80 )
        {
            temperatureInCelsius = -temperatureInCelsius;
        }
        float temperatureInFarenheit = temperatureInCelsius * 1.8f + 32;
        emit DHT22readData(humidity, temperatureInCelsius, temperatureInFarenheit);
    }else
    {
        printf( "Data not good, skip\n" );
    }
}
