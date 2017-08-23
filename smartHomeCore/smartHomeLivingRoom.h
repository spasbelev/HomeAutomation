#ifndef SMARTHOMELIVINGROOM_H
#define SMARTHOMELIVINGROOM_H

class homeCommunication;

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
    double livingRoomTemperature;
    double livingRoomHumidity;
    int livingRoomLightPower;
    homeCommunication &mHomeCommunicationPort;
};

#endif // SMARTHOMELIVINGROOM_H
