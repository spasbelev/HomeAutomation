#include "smartHomeKitchen.h"
#include "homeCommunication.h"

smartHomeKitchen::smartHomeKitchen() : mHomeCommunicationPort(homeCommunication::returnInstance())
{

}


double smartHomeKitchen::getKitchenRoomTemperature() const noexcept
{
    return this->kitchenRoomTemperature;
}

double smartHomeKitchen::getKitchenRoomHumidity() const noexcept
{
    return this->kitchenRoomHumidity;
}

int smartHomeKitchen::getKitchenRoomLuminocity() const noexcept
{
    return this->kitchenRoomLightPower;
}

/*Setters for room temperature, and light power */
void smartHomeKitchen::setKitchenRoomTemperature(const double temperature)
{
    this->mHomeCommunicationPort.sendInformation(temperature);
}

void smartHomeKitchen::setKitchenRoomLightPower(const int lightPower)
{
    this->mHomeCommunicationPort.sendInformation(lightPower);
}

void smartHomeKitchen::getInformation()
{

}
