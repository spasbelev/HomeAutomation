#include "smartHomeLivingRoom.h"
#include "homeCommunication.h"

smartHomeLivingRoom::smartHomeLivingRoom() : mHomeCommunicationPort(homeCommunication::returnInstance())
{

}

double smartHomeLivingRoom::getLivingRoomTemperature() const
{
    return this->livingRoomTemperature;
}
double smartHomeLivingRoom::getLivingRoomHumidity() const
{
    return this->livingRoomHumidity;
}
int smartHomeLivingRoom::getLivingRoomLuminocity() const
{
    return this->livingRoomLightPower;
}

/*Setters for room temperature, and light power */
void smartHomeLivingRoom::setLivingRoomTemperature(const double temperature)
{
    this->livingRoomTemperature = temperature;
    this->mHomeCommunicationPort.sendInformation(temperature);
}

void smartHomeLivingRoom::setLivingRoomLightPower(const int lightPower)
{
    this->livingRoomLightPower = lightPower;
    this->mHomeCommunicationPort.sendInformation(lightPower);

}
