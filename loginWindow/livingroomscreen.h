#ifndef LIVINGROOMSCREEN_H
#define LIVINGROOMSCREEN_H

#include <QMainWindow>

namespace Ui {
class livingRoomScreen;
}

class livingRoomScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit livingRoomScreen(QWidget *parent = 0);
    ~livingRoomScreen();

private:
    Ui::livingRoomScreen *ui;

public slots:
    void updateTemperatureDataForLivingRoom(int temperatureInLivingRoom);
    void updateHumidityDataForLivingRoom(int humidityInLivingRoom);
};

#endif // LIVINGROOMSCREEN_H
