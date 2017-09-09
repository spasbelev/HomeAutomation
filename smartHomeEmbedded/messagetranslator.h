#ifndef MESSAGETRANSLATOR_H
#define MESSAGETRANSLATOR_H

#include <QObject>
#include <livingroommanager.h>

class messageTranslator : public QObject
{
    Q_OBJECT
public:
    explicit messageTranslator(QObject *parent = 0);
    ~messageTranslator();
    void startDHTSensorThread();

private:
    LivingRoomManager *LivingRoomManagerObj;

signals:

public slots:
    void translateMessage(QByteArray message);
};

#endif // MESSAGETRANSLATOR_H
