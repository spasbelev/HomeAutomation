#include "livingroomscreen.h"
#include "ui_livingroomscreen.h"
#include "communicationlibrary.h"

livingRoomScreen::livingRoomScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::livingRoomScreen)
{
    ui->setupUi(this);

    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateTemperatureForLivingRoom(int)),
                     this, SLOT(updateHumidityDataForLivingRoom(int)));

    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateHumidityForLivingRoom(int)),
                     this, SLOT(updateTemperatureDataForLivingRoom(int)));
}

livingRoomScreen::~livingRoomScreen()
{
    delete ui;
}

void livingRoomScreen::updateTemperatureDataForLivingRoom(int temperatureInLivingRoom)
{
    this->ui->degrees->setText( QString::number(temperatureInLivingRoom));
}

void livingRoomScreen::updateHumidityDataForLivingRoom(int humidityInLivingRoom)
{
    this->ui->humidityPercent->setText( QString::number(humidityInLivingRoom));
}
