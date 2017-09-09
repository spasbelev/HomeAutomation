#ifndef LIVINGROOMMANAGER_H
#define LIVINGROOMMANAGER_H

#include <QObject>

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

signals:

public slots:
};

#endif // LIVINGROOMMANAGER_H
