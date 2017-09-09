#include <iostream>
#include <communicationlibrary.h>
#include <QThread>
#include <QCoreApplication>
#include <sensorsmanager.h>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication serverApp(argc, argv);
    cout << "Hello World!" << endl;
//    QThread *serverCommunicationThread = new QThread;

    communicationLibrary *communicationLibraryObj = new communicationLibrary();

//    communicationLibraryObj->moveToThread(serverCommunicationThread);

//    QObject::connect(serverCommunicationThread, SIGNAL(started()), communicationLibraryObj, SLOT(process()));
//    QObject::connect(communicationLibraryObj, SIGNAL(finished()), serverCommunicationThread, SLOT(quit()));
//    QObject::connect(serverCommunicationThread, SIGNAL(finished()), communicationLibraryObj, SLOT(deleteLater()));
    bool didConnectSucceed = communicationLibraryObj->connect();
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
