#include "smartHomeLivingRoom.h"
#include "communicationlibrary.h"

#include "communicationmessagesdefinition.h"

enum
{
    SET_TEMPERATURE,
    SET_LIGHT_POWER,
};

smartHomeLivingRoom::smartHomeLivingRoom() : mHomeCommunicationPort((CommunicationLibrary::returnInstance()))
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
    this->array[0] = SET_TEMPERATURE;
    this->array[1] = static_cast<uint8_t>(temperature);
    this->mHomeCommunicationPort->sendInformation(SET_LIVINGROOM_TEMPERATURE,array);
}

void smartHomeLivingRoom::setLivingRoomLightPower(const int lightPower)
{
    this->livingRoomLightPower = lightPower;
    this->mHomeCommunicationPort->sendInformation(SET_LIVINGROOM_LIGHT_POWER,lightPower);

}
