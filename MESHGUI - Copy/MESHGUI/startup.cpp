#include "startup.h"
#include "ui_startup.h"
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
Startup::Startup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Startup)
{
    ui->setupUi(this);
    _MainWindow = new MainWindow(this);
}

Startup::~Startup()
{
    delete _MainWindow;
    delete ui;
}

void Startup::on_buttonBox_accepted()
{
    COM_Port = ui->lineEdit->text();
    QMessageBox::information(this, "title", COM_Port);
        if(COM_Port != "")
        {
            _MainWindow->show();
            hide();
        }

}
