#ifndef HOMECOMMUNICATION_H
#define HOMECOMMUNICATION_H

#include <QString>
#include <QSsl>
#include <QtNetwork>
#include <memory>
#include <QDialog>

class homeCommunication : public QDialog
{
    Q_OBJECT
public:

    template <typename dataTypeToBeSent>
    void sendInformation(int messageType, dataTypeToBeSent dataToSend);

    template <typename dataTypeToBeSent>
    dataTypeToBeSent reuqestInformation(int requestForSpecificType);
    static homeCommunication& returnInstance();
    ~homeCommunication();
//    homeCommunication(const homeCommunication &homeCommunication);
    homeCommunication();


private:
    void displayError(QAbstractSocket::SocketError socketError);
    void disconnect() const;
    void connect();
    void prepareNetworkConfiguration();


private:
    static homeCommunication singletonInstance;
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
//    void updateTemperatureForKitchen(int temperatureInKitchen);
//    void updateHumidityForKitchen(int temperatureInKitchen);

};

#endif // HOMECOMMUNICATION_H
