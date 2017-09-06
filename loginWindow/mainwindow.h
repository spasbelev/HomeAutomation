#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainscreenwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_shutdown_clicked();

private:
    Ui::MainWindow *ui;
    mainScreenWindow *mainScreenWindowObj;
};

#endif // MAINWINDOW_H
