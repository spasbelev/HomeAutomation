#include "communicationlibrary.h"
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork>

communicationLibrary::communicationLibrary(QObject *parent) : QObject(parent)
{
    QObject::connect(tcpServer, SIGNAL(readyRead()), this, SLOT(readTcpData()));
}

bool communicationLibrary::connect()
{
    tcpServer = new QTcpServer;
    if(!tcpServer->listen(QHostAddress::Any, 80))
    {
//        sendErrorToModel("Unable to start the server.");
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

    return true;
}


void communicationLibrary::newConnection()
{
    QTcpSocket *tcpSocket = tcpServer->nextPendingConnection();
    if(tcpSocket->waitForBytesWritten(30000))
    {
        // get the data and decide what to do
    }
}

void communicationLibrary::DHT22readData(int humidity, int temperatureInCelsius, int temperatureInFarenheit)
{

}
