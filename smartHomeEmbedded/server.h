#ifndef COMMUNICATIONLIBRARY_H
#define COMMUNICATIONLIBRARY_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <vector>

class server : public QTcpServer
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
    explicit server(QObject *parent = 0);
    bool connect();
    ~server();

signals:
    void finished();
    void translateMessage(QByteArray message, QTcpSocket *newTcpSocket);

public slots:
    void acceptConnection();
};

#endif // COMMUNICATIONLIBRARY_H
