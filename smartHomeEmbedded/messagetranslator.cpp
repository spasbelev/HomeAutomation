#include "messagetranslator.h"
#include "communicationmessagesdefinition.h"

messageTranslator::messageTranslator(QObject *parent) : QObject(parent)
{
    LivingRoomManagerObj = LivingRoomManager::getInstance();

}

messageTranslator::~messageTranslator()
{
    LivingRoomManagerObj = nullptr;
    delete LivingRoomManagerObj;
}


void messageTranslator::translateMessage(QByteArray message)
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
