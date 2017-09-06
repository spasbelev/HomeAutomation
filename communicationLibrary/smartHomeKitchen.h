#ifndef SMARTHOMEKITCHEN_H
#define SMARTHOMEKITCHEN_H

#include <QObject>


class CommunicationLibrary;
class QByteArray;

class smartHomeKitchen : public QObject
{
    Q_OBJECT
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
    CommunicationLibrary *mHomeCommunicationPort;
public slots:
    void getInformationForKitchen(QByteArray receivedData);
};

#endif // SMARTHOMEKITCHEN_H
