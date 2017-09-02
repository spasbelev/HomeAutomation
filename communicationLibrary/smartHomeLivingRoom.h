#ifndef SMARTHOMELIVINGROOM_H
#define SMARTHOMELIVINGROOM_H

#include <memory>

class CommunicationLibrary;

class smartHomeLivingRoom
{
public:
    smartHomeLivingRoom();
    /* Getter functions for the different sensosrs in a kitchen */
    double getLivingRoomTemperature() const;
    double getLivingRoomHumidity() const;
    int getLivingRoomLuminocity() const;

    /*Setters for room temperature, and light power */
    void setLivingRoomTemperature(const double temperature);
    void setLivingRoomLightPower(const int lightPower);

private:
    void getInformation();

private:
    static uint8_t array[5];
    double livingRoomTemperature;
    double livingRoomHumidity;
    int livingRoomLightPower;
    CommunicationLibrary &mHomeCommunicationPort;
};

#endif // SMARTHOMELIVINGROOM_H
