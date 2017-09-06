#ifndef COMMUNICATIONMESSAGESDEFINITION_H
#define COMMUNICATIONMESSAGESDEFINITION_H

typedef enum
{
    SET_LIVINGROOM_TEMPERATURE,
    SET_LIVINGROOM_LIGHT_POWER,
    GET_LIVINGROOM_TEMPERATURE,
    GET_LIVINGROOM_LIGHT_POWER,
    GET_LIVINGROOM_HUMIDITY,

    SET_KITCHEN_TEMPERATURE,
    SET_KITCHEN_LIGHT_POWER,
    GET_KITCHEN_TEMPERATURE,
    GET_KITCHEN_LIGHT_POWER,
    GET_KITCHEN_HUMIDITY,

    SET_BEDROOM_TEMPERATURE,
    SET_BEDROOM_LIGHT_POWER,
    GET_BEDROOM_TEMPERATURE,
    GET_BEDROOM_LIGHT_POWER,
    GET_BEDROOM_HUMIDITY,

    SET_BATHROOM_TEMPERATURE,
    SET_BATHROOM_LIGHT_POWER,
    GET_BATHROOM_TEMPERATURE,
    GET_BATHROOM_LIGHT_POWER,
    GET_BATHROOM_HUMIDITY,
    LAST_ROOM_MESSAGE,
}RoomMessages;

typedef enum
{
    START_OF_SIGNAL = LAST_ROOM_MESSAGE,
    ACTIVATE_ALARM,
    DEACTIVATE_ALARM,
}BathroomMessages;

#endif // COMMUNICATIONMESSAGESDEFINITION_H
