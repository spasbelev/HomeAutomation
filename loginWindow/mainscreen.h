#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include "communicationlibrary.h"

class mainScreen : public QWidget
{
    Q_OBJECT
private:

public:
    explicit mainScreen(QWidget *parent = 0);

signals:

public slots:
    void updateTemperatureDataForKitchen(int temperatureInKitchen);
    void updateHumidityDataForKitchen(int humidityInKitchen);

};

#endif // MAINSCREEN_H
