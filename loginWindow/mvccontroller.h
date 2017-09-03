#ifndef MVCCONTROLLER_H
#define MVCCONTROLLER_H

#include <QObject>
#include <memory>
#include "communicationlibrary.h"
#include "mainscreenwindow.h"

class MVCController : public QObject
{
    Q_OBJECT
public:
    explicit MVCController(QObject *parent = 0);



signals:


public slots:


private:

};

#endif // MVCCONTROLLER_H
