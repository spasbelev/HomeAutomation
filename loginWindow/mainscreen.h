#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>

class mainScreen : public QWidget
{
    Q_OBJECT
public:
    explicit mainScreen(QWidget *parent = 0);

signals:

public slots:
    void updateTemperatureForKitchen(int temperatureInKitchen);
    void updateHumidityForKitchen(int humidityInKitchen);

};

#endif // MAINSCREEN_H
