#include "mainscreen.h"

mainScreen::mainScreen(QWidget *parent) : QWidget(parent)
{
    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateTemperatureForKitchen(int temperatureInKitchen)),
                     this, SLOT(updateTemperatureDataForKitchen(int temperatureInKitchen)));

    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateHumidityForKitchen(int humidityInKitchen)),
                     this, SLOT(updateHumidityForKitchen(int humidityInKitchen)));
}

void mainScreen::updateHumidityDataForKitchen(int humidityInKitchen)
{
    (void)humidityInKitchen;
}

void mainScreen::updateTemperatureDataForKitchen(int temperatureInKitchen)
{
    (void)temperatureInKitchen;
}
