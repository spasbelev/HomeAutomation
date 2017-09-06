#include "communicationlibrary.h"
#include <QtNetwork/QDnsLookup>
#include <future>




typedef enum
{
    MESSAGE_WITH_INFORMATION_FROM_KITCHEN,
    MESSAGE_WITH_INFORMATION_FROM_LIVINGROOM,
    MESSAGE_WITH_INFORMATION_FROM_BATHROOM
}specificRoomMessage;

CommunicationLibrary* CommunicationLibrary::singletonInstance = new CommunicationLibrary();

CommunicationLibrary::CommunicationLibrary() : localMachineName(QHostInfo::localHostName())
{
    this->connect();
    QObject::connect(this->tcpSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
    QObject::connect(this, SIGNAL(getInformationReady()), SLOT(notifyGUI()));
}

//homeCommunication::homeCommunication(const homeCommunication &homeCommunication)
//{

//}

CommunicationLibrary::~CommunicationLibrary()
{
    this->disconnect();
}

template <typename dataTypeToBeSent>
void CommunicationLibrary::sendInformation(int messageType, dataTypeToBeSent dataToSend)
{
    memcpy(&dataPacketToBeSent, messageType,sizeof(messageType) );
    memcpy(dataPacketToBeSent + 1, dataToSend, sizeof(dataToSend));
    tcpSocket->writeData(dataPacketToBeSent, sizeof(dataPacketToBeSent));
}

template <typename dataTypeToBeSent>
dataTypeToBeSent CommunicationLibrary::reuqestInformation(int requestForSpecificType)
{
    sendInformation(requestForSpecificType,0);
    QByteArray receivedData =  tcpSocket->readAll();
}

CommunicationLibrary* CommunicationLibrary::returnInstance()
{
    return singletonInstance;
}

void CommunicationLibrary::connect()
{
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    QHostAddress *hostAddres = new QHostAddress("192.168.0.1");
    tcpSocket = new QTcpSocket();
    tcpSocket->connectToHost(hostAddres->toString(),80, QTcpSocket::ReadWrite);

    if(tcpSocket->waitForConnected(3000))
    {
//        QMessageBox::information(this, "Connection timeout",
//                                 "Cannot connect to host. Please check your internet connection or make sure that the host is running");
        tcpSocket->close();
    }
}

void CommunicationLibrary::disconnect() const
{
    tcpSocket->close();
    delete tcpSocket;
}

void CommunicationLibrary::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
//        QMessageBox::information(this,"Connection error",
//                                 "The host was not found. Please check the "
//                                    "host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
//        QMessageBox::information(this, "Connection error",
//                                 "The connection was refused by the peer. "
//                                    "Make sure the fortune server is running, "
//                                    "and check that the host name and port "
//                                    "settings are correct.");
        break;
    default:

        break;
    }
}
void CommunicationLibrary::notifyGUI()
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

void CommunicationLibrary::readTcpData()
{
    this->dataReceived = tcpSocket->readAll();
    emit getInformationReady();
}

