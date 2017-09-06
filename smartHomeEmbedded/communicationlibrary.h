#ifndef COMMUNICATIONLIBRARY_H
#define COMMUNICATIONLIBRARY_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class communicationLibrary : public QObject
{
    Q_OBJECT
private:
    QTcpServer *tcpServer;
    QString ipAddress;
    QByteArray dataReceived;
public:
    explicit communicationLibrary(QObject *parent = 0);
    bool connect();

signals:

public slots:
    void newConnection();
    void DHT22readData(int humidity, int temperatureInCelsius, int temperatureInFarenheit);
};

#endif // COMMUNICATIONLIBRARY_H
