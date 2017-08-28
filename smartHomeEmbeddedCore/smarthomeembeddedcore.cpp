#include "smarthomeembeddedcore.h"
#include <QtNetwork>
#include "wiringPi.h"

SmartHomeEmbeddedCore::SmartHomeEmbeddedCore()
{
    tcpServer = new QTcpServer;
    if(!tcpServer->listen())
    {
        sendErrorToModel("Unable to start the server.");
        tcpServer->close();
    }


    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    wiringPiSetup();
}

SmartHomeEmbeddedCore& SmartHomeEmbeddedCore::getServerInstance()
{
    return smartHomeServer;
}
