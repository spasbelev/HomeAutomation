#include "livingroommanager.h"
#include <QThread>


LivingRoomManager* LivingRoomManager::LivingRoomManagerObj = new LivingRoomManager;

LivingRoomManager::LivingRoomManager(QObject *parent) : QObject(parent)
{

}

void LivingRoomManager::setHumidity(double newHumidityData)
{
    this->humidity = newHumidityData;
}

void LivingRoomManager::setTemperatureData(double newTemperatureData)
{
    this->temperature = newTemperatureData;

}

LivingRoomManager* LivingRoomManager::getInstance()
{
    return LivingRoomManagerObj;

}
