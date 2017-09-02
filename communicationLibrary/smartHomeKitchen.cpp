#include <QByteArray>

#include "smartHomeKitchen.h"
#include "communicationlibrary.h"
#include "communicationmessagesdefinition.h"

smartHomeKitchen::smartHomeKitchen() : mHomeCommunicationPort(CommunicationLibrary::returnInstance())
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
    this->mHomeCommunicationPort.sendInformation(SET_KITCHEN_TEMPERATURE, temperature);
}

void smartHomeKitchen::setKitchenRoomLightPower(const int lightPower)
{
    this->mHomeCommunicationPort.sendInformation(SET_KITCHEN_LIGHT_POWER, lightPower);
}

void smartHomeKitchen::getInformation()
{

}
