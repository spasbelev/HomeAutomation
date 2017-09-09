#include "mainwindow.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QThread *guiThread = new QThread;

    QObject::connect(guiThread, SIGNAL(started()), &w, SLOT(process()));
    QObject::connect(&w, SIGNAL(finished()), guiThread, SLOT(quit()));
    QObject::connect(guiThread, SIGNAL(finished()), &w, SLOT(deleteLater()));

    w.moveToThread(guiThread);
    w.show();
    guiThread->start();

    return a.exec();
}
