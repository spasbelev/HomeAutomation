#ifndef COMMUNICATIONLIBRARY_H
#define COMMUNICATIONLIBRARY_H

#include <QtNetwork>

class QByteArray;
#include <QAbstractSocket>
#include <QNetworkConfigurationManager>
#include "communicationmessagesdefinition.h"

class CommunicationLibrary : public QObject
{
    Q_OBJECT
public:

    template <typename dataTypeToBeSent>
    void sendInformation(int messageType, dataTypeToBeSent dataToSend);

//    template <typename dataTypeToBeSent>
    void reuqestInformation(RoomMessages requestForSpecificType);
    static CommunicationLibrary* returnInstance();
    ~CommunicationLibrary();
    CommunicationLibrary(const CommunicationLibrary &CommunicationLibraryInstance)=default;



private:
    void displayError(QAbstractSocket::SocketError socketError);
    void disconnect() const;
    void connect();
    void prepareNetworkConfiguration();


private:
    CommunicationLibrary();
    static CommunicationLibrary *singletonInstance;
    QNetworkConfigurationManager manager;
    QNetworkSession *networkSession;
    QString localMachineName;
    QByteArray dataReceived;
    QByteArray dataPacketToBeSent;
    QString hostName;
    quint16 port;
    QTcpSocket *tcpSocket;


public slots:
    void readTcpData();
    void notifyGUI();


signals:
    void getInformationReady();
    void updateTemperatureForKitchen(int temperatureInKitchen);
    void updateHumidityForKitchen(int temperatureInKitchen);
    void updateTemperatureForLivingRoom(int temperatureInKLivingRoom);
    void updateHumidityForLivingRoom(int temperatureInLivingRoom);
    void errorMessage(QString errorMessage);
};

#endif // COMMUNICATIONLIBRARY_H
