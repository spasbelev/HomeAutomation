#ifndef LIVINGROOMMANAGER_H
#define LIVINGROOMMANAGER_H

#include <QObject>


class QTcpSocket;

class LivingRoomManager : public QObject
{
    Q_OBJECT

private:
    explicit LivingRoomManager(QObject *parent = 0);
    double humidity;
    double temperature;
    static LivingRoomManager *LivingRoomManagerObj;

public:
    void setHumidity(double newHumidityData);
    void setTemperatureData(double newTemperatureData);
    static LivingRoomManager* getInstance();
    void readDHT22Data();
    QTcpSocket *respondSocket;

signals:
    void temperatureChanged(int temperatureInCelsius);
    void sendData(QByteArray data,QTcpSocket *whereToSend);


public slots:
    void startMonitoringLivingRoom(QTcpSocket *newTcpSocket);
};

#endif // LIVINGROOMMANAGER_H
