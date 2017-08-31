#ifndef CONTROLLERFORMVCPATTERN_H
#define CONTROLLERFORMVCPATTERN_H

#include <QObject>

class controllerForMVCPattern : public QObject
{
    Q_OBJECT
public:
    explicit controllerForMVCPattern(QObject *parent = 0);

signals:

public slots:
};

#endif // CONTROLLERFORMVCPATTERN_H