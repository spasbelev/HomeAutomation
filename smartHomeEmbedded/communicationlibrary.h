#ifndef COMMUNICATIONLIBRARY_H
#define COMMUNICATIONLIBRARY_H

#include <QObject>

class QTcpSocket;
class communicationLibrary : public QObject
{
    Q_OBJECT
public:
    explicit communicationLibrary(QObject *parent = 0);

signals:

public slots:
    void sendData(QByteArray data, QTcpSocket *whereToSend);
};

#endif // COMMUNICATIONLIBRARY_H
