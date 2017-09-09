#include "mainscreenwindow.h"
#include "ui_mainscreenwindow.h"
#include "communicationlibrary.h"
#include <QMessageBox>
#include <cstdarg>
#include <communicationmessagesdefinition.h>

mainScreenWindow::mainScreenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainScreenWindow)
{
    ui->setupUi(this);

//    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateTemperatureForKitchen(int temperatureInKitchen)),
//                     this, SLOT(updateTemperatureDataForKitchen(int temperatureInKitchen)));

//    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(updateHumidityForKitchen(int humidityInKitchen)),
//                     this, SLOT(updateHumidityForKitchen(int humidityInKitchen)));

    QObject::connect(CommunicationLibrary::returnInstance(), SIGNAL(errorMessage(QString )),
                                                                    this, SLOT(showErrorMessage(QString)));
    CommunicationLibrary::returnInstance()->reuqestInformation(GET_LIVINGROOM_TEMPERATURE);
}

mainScreenWindow::~mainScreenWindow()
{
    delete ui;
}


void mainScreenWindow::updateTemperatureDataForKitchen(int temperatureInKitchen)
{
    (void)temperatureInKitchen;
}
void mainScreenWindow::updateHumidityDataForKitchen(int humidityInKitchen)
{
    (void)humidityInKitchen;
}

void mainScreenWindow::showErrorMessage(QString messages...)
{
    va_list args;
    va_start(args, messages);

    QMessageBox::information(this, "Error Message", va_arg(args, QString));
}

void mainScreenWindow::on_bedroom_clicked()
{
    livingRoomScreenObj = new livingRoomScreen(this);
    hide();
    livingRoomScreenObj->show();
}
