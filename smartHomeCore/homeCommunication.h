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
    void sendInformation(dataTypeToBeSent dataToSend) const;

    template <typename dataTypeToBeSent>
    dataTypeToBeSent getInformation() const;
    static homeCommunication& returnInstance();

private:
    void displayError(QAbstractSocket::SocketError socketError);
    void disconnect() const;
    ~homeCommunication();
    void connect();
    homeCommunication();
    void prepareNetworkConfiguration();


private:
    static homeCommunication singletonInstance;
    QNetworkConfigurationManager manager;
    QNetworkSession *networkSession;
    QString localMachineName;
    QByteArray dataReceived;
    QString hostName;
    quint16 port;
    QTcpSocket *tcpSocket;

public slots:
    void readTcpData();


};

#endif // HOMECOMMUNICATION_H
