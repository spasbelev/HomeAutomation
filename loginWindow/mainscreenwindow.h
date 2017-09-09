#ifndef MAINSCREENWINDOW_H
#define MAINSCREENWINDOW_H

#include <QMainWindow>
#include "livingroomscreen.h"

namespace Ui {
class mainScreenWindow;
}

class mainScreenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainScreenWindow(QWidget *parent = 0);
    ~mainScreenWindow();

private:
    Ui::mainScreenWindow *ui;
    livingRoomScreen *livingRoomScreenObj;



public slots:
    void updateTemperatureDataForKitchen(int temperatureInKitchen);
    void updateHumidityDataForKitchen(int humidityInKitchen);
    void showErrorMessage(QString messages...);
private slots:
    void on_bedroom_clicked();

signals:
    void sendInformationToServer(int messageType, QByteArray dataToSend);

};

#endif // MAINSCREENWINDOW_H
