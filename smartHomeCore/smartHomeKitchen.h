#ifndef SMARTHOMEKITCHEN_H
#define SMARTHOMEKITCHEN_H


class homeCommunication;

class smartHomeKitchen
{
public:
    smartHomeKitchen();
    /* Getter functions for the different sensosrs in a kitchen */
    double getKitchenRoomTemperature() const noexcept;
    double getKitchenRoomHumidity() const noexcept;
    int getKitchenRoomLuminocity() const noexcept;

    /*Setters for room temperature, and light power */
    void setKitchenRoomTemperature(const double temperature);
    void setKitchenRoomLightPower(const int lightPower);

private:
    void getInformation();

private:
    double kitchenRoomTemperature;
    double kitchenRoomHumidity;
    int kitchenRoomLightPower;
    homeCommunication &mHomeCommunicationPort;
};

#endif // SMARTHOMEKITCHEN_H
