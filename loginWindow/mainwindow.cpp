#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if(username ==  "root" && password == "1234") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        //hide();
//        secDialog = new SecDialog(this);
//        secDialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username or password is not correct");
    }
}

void MainWindow::on_shutdown_clicked()
{

}
