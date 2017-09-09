#include <iostream>
#include <server.h>
#include <QThread>
#include <QCoreApplication>
#include <livingroommanager.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication serverApp(argc, argv);
    cout << "Hello World!" << endl;
//    QThread *serverCommunicationThread = new QThread;

    server *serverObj = new server();
    LivingRoomManager *LivingRoomManagerObj = LivingRoomManager::getInstance();
    QThread *livingRoomThread = new QThread;
    LivingRoomManagerObj->moveToThread(livingRoomThread);

//    communicationLibraryObj->moveToThread(serverCommunicationThread);

//    QObject::connect(serverCommunicationThread, SIGNAL(started()), communicationLibraryObj, SLOT(process()));
//    QObject::connect(communicationLibraryObj, SIGNAL(finished()), serverCommunicationThread, SLOT(quit()));
//    QObject::connect(serverCommunicationThread, SIGNAL(finished()), communicationLibraryObj, SLOT(deleteLater()));
    bool didConnectSucceed = serverObj->connect();
    if(didConnectSucceed)
    {
        cout << "Success";
    }
    else
    {
        cout << "fail";
    }
//    serverCommunicationThread->start();

    return serverApp.exec();
}
