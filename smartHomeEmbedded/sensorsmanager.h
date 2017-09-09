#ifndef SENSORSMANAGER_H
#define SENSORSMANAGER_H

#include <QObject>

class sensorsManager : public QObject
{
    Q_OBJECT
public:
    explicit sensorsManager(QObject *parent = 0);
    void readDHT22Data();
    void startDHTSensorThread();

signals:
    void DHT22readData(int humidity, int temperatureInCelsius, int temperatureInFarenheit);

public slots:
};

#endif // SENSORSMANAGER_H
