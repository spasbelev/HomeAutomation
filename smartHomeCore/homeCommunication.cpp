#include "homeCommunication.h"
#include <QtNetwork/QDnsLookup>
#include <QMessageBox>


homeCommunication::homeCommunication() : localMachineName(QHostInfo::localHostName())
{
    this->connect();
    QObject::connect(this->tcpSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
}

homeCommunication::~homeCommunication()
{
    this->disconnect();
}

template <typename dataTypeToBeSent>
void homeCommunication::sendInformation(dataTypeToBeSent dataToSend) const
{
    tcpSocket->writeData(dataToSend, sizeof(dataToSend));
}

template <typename dataTypeToBeSent>
dataTypeToBeSent homeCommunication::getInformation() const
{

}

homeCommunication& homeCommunication::returnInstance()
{
    return singletonInstance;
}

void homeCommunication::connect()
{
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    tcpSocket->connectToHost(this->hostName,this->port, QTcpSocket::ReadWrite);

    if(tcpSocket->waitForConnected(300000))
    {
        QMessageBox::information(this, "Connection timeout",
                                 "Cannot connect to host. Please check your internet connection or make sure that the host is running");
        tcpSocket->close();
    }
}

void homeCommunication::disconnect() const
{
    tcpSocket->close();
    delete tcpSocket;
}

void homeCommunication::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this,"Connection error",
                                 "The host was not found. Please check the "
                                    "host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "Connection error",
                                 "The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct.");
        break;
    default:
        QMessageBox::information(this, "FConnection error",
                                 "The following error occurred: %1.",
                                 tcpSocket->errorString());
    }

}

void homeCommunication::readTcpData()
{
    this->dataReceived = tcpSocket->readAll();
}
