#ifndef MESSAGETRANSLATOR_H
#define MESSAGETRANSLATOR_H

#include <QObject>

class QTcpSocket;

class messageTranslator : public QObject
{
    Q_OBJECT
public:
    explicit messageTranslator(QObject *parent = 0);
    ~messageTranslator();

private:

signals:
    void startMonitoringLivingRoom(QTcpSocket *newTcpSocket);

public slots:
    void translateMessage(QByteArray message, QTcpSocket *newTcpSocket);
};

#endif // MESSAGETRANSLATOR_H
