#include "smarthomeembeddedcore.h"
#include <QtNetwork>
#include "wiringPi.h"

SmartHomeEmbeddedCore::SmartHomeEmbeddedCore()
{


    wiringPiSetup();
}

SmartHomeEmbeddedCore& SmartHomeEmbeddedCore::getServerInstance()
{
    return smartHomeServer;
}
