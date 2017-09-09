#include "messagetranslator.h"
#include "communicationmessagesdefinition.h"
#include <QTcpSocket>

messageTranslator::messageTranslator(QObject *parent) : QObject(parent)
{

}

messageTranslator::~messageTranslator()
{

}


void messageTranslator::translateMessage(QByteArray message, QTcpSocket *newTcpSocket)
{
    uint8_t messageType = message[0];
    switch(messageType)
    {
        case SET_LIVINGROOM_TEMPERATURE:
        {

            break;
        }
        case SET_LIVINGROOM_LIGHT_POWER:
        {
            break;
        }
        case GET_LIVINGROOM_LIGHT_POWER:
        {
            break;
        }
        case GET_LIVINGROOM_TEMPERATURE:
        case GET_LIVINGROOM_HUMIDITY:
        {
            emit startMonitoringLivingRoom(newTcpSocket);
            break;

        }

        case SET_KITCHEN_TEMPERATURE:
        {
            break;

        }
        case SET_KITCHEN_LIGHT_POWER:
        {
            break;

        }
        case GET_KITCHEN_TEMPERATURE:
        {
            break;

        }
        case GET_KITCHEN_LIGHT_POWER:
        {
            break;

        }
        case GET_KITCHEN_HUMIDITY:
        {
            break;

        }

        case SET_BEDROOM_TEMPERATURE:
        {
            break;

        }
        case SET_BEDROOM_LIGHT_POWER:
        {
            break;

        }
        case GET_BEDROOM_TEMPERATURE:
        {
            break;

        }
        case GET_BEDROOM_LIGHT_POWER:
        {
            break;

        }
        case GET_BEDROOM_HUMIDITY:
        {
            break;

        }

        case SET_BATHROOM_TEMPERATURE:
        {
            break;

        }
        case SET_BATHROOM_LIGHT_POWER:
        {
            break;
        }
        case GET_BATHROOM_TEMPERATURE:
        {
            break;

        }
        case GET_BATHROOM_LIGHT_POWER:
        {
            break;

        }
        case GET_BATHROOM_HUMIDITY:
        {
            break;

        }
    }
}
