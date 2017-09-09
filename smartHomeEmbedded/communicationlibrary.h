#ifndef COMMUNICATIONLIBRARY_H
#define COMMUNICATIONLIBRARY_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <vector>

class communicationLibrary : public QTcpServer
{
    Q_OBJECT
private:
    QTcpServer *tcpServer;
    QString ipAddress;
    QByteArray dataReceived;
//    std::vector<QTcpSocket*> tcpConnections;
    QTcpSocket *tcpSocket;
    void readData();
public:
    explicit communicationLibrary(QObject *parent = 0);
    bool connect();
    ~communicationLibrary();

signals:
    void finished();
    void translateMessage(QByteArray message);

public slots:
    void acceptConnection();
};

#endif // COMMUNICATIONLIBRARY_H
