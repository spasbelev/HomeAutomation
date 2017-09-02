#include "mvccontroller.h"

MVCController::MVCController(QObject *parent) : QObject(parent)
{
    this->homeCommunicationObj = std::make_shared<CommunicationLibrary>(std::move(CommunicationLibrary::returnInstance()));
    this->mainScreenObj = std::make_shared<mainScreen>();
}

