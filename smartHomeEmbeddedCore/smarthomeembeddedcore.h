#ifndef SMARTHOMEEMBEDDEDCORE_H
#define SMARTHOMEEMBEDDEDCORE_H

#include "smarthomeembeddedcore_global.h"
#include <QTcpServer>
#include <QTcpSocket>


class SMARTHOMEEMBEDDEDCORESHARED_EXPORT SmartHomeEmbeddedCore
{

public:
    static SmartHomeEmbeddedCore &getServerInstance();


private:
    SmartHomeEmbeddedCore();
    ~SmartHomeEmbeddedCore();
    void sendErrorToModel(QString errorString);

private:
    QTcpServer *tcpServer;
     QString ipAddress;
    static SmartHomeEmbeddedCore smartHomeServer;
};

#endif // SMARTHOMEEMBEDDEDCORE_H
