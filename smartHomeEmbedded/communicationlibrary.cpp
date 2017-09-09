#include "communicationlibrary.h"
#include <QTcpSocket>

communicationLibrary::communicationLibrary(QObject *parent) : QObject(parent)
{

}


void communicationLibrary::sendData(QByteArray data, QTcpSocket *whereToSend)
{

}
