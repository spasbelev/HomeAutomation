#include "homeCommunication.h"
#include <QtNetwork/QDnsLookup>
#include <QMessageBox>
#include <future>


typedef enum
{
    MESSAGE_WITH_INFORMATION_FROM_KITCHEN,
    MESSAGE_WITH_INFORMATION_FROM_LIVINGROOM,
    MESSAGE_WITH_INFORMATION_FROM_BATHROOM
}specificRoomMessage;

homeCommunication::homeCommunication() : localMachineName(QHostInfo::localHostName())
{
    this->connect();
    QObject::connect(this->tcpSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
    QObject::connect(this, SIGNAL(getInformationReady()), SLOT(notifyGUI()));
}

homeCommunication::~homeCommunication()
{
    this->disconnect();
}

template <typename dataTypeToBeSent>
void homeCommunication::sendInformation(int messageType, dataTypeToBeSent dataToSend)
{
    memcpy(&dataPacketToBeSent, messageType,sizeof(messageType) );
    memcpy(dataPacketToBeSent + 1, dataToSend, sizeof(dataToSend));
    tcpSocket->writeData(dataPacketToBeSent, sizeof(dataPacketToBeSent));
}

template <typename dataTypeToBeSent>
dataTypeToBeSent homeCommunication::reuqestInformation(int requestForSpecificType)
{
    sendInformation(requestForSpecificType,0);
    QByteArray receivedData =  tcpSocket->readAll();
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
void homeCommunication::notifyGUI()
{
    uint8_t messageTye = this->dataReceived[0];

    switch(messageTye)
    {
        case MESSAGE_WITH_INFORMATION_FROM_KITCHEN:
        {

        }
        case MESSAGE_WITH_INFORMATION_FROM_LIVINGROOM:
        {

        }
        case MESSAGE_WITH_INFORMATION_FROM_BATHROOM:
        {
        }
    }
}

void homeCommunication::readTcpData()
{
    this->dataReceived = tcpSocket->readAll();
    emit getInformationReady();
}
