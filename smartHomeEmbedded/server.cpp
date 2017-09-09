#include "server.h"
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork>

server::server(QObject *parent) : QTcpServer(parent)
{
    tcpServer = new QTcpServer;

    QObject::connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

bool server::connect()
{

    if(!this->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "Could not start";
        tcpServer->close();
    }
    else
    {
        qDebug() << "Listening to port" << 8080;
    }


//    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
//    // use the first non-localhost IPv4 address
//    for (int i = 0; i < ipAddressesList.size(); ++i) {
//        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
//            ipAddressesList.at(i).toIPv4Address()) {
//            ipAddress = ipAddressesList.at(i).toString();
//            break;
//        }
//    }
//    // if we did not find one, use IPv4 localhost
//    if (ipAddress.isEmpty())
//        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    return true;
}


void server::acceptConnection()
{
    this->tcpSocket = tcpServer->nextPendingConnection();

    QObject::connect(this->tcpSocket, SIGNAL(readyRead()),
                this->tcpServer, SLOT(readData()));
}

void server::readData()
{
    QByteArray bytesReceived = this->tcpSocket->readAll();
    emit translateMessage(bytesReceived, tcpSocket);
}



server::~server()
{
    emit finished();
}
