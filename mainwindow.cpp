#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
QSerialPort *serial;

//void onRead(){
//    qDebug() << "onRead()";
//    qDebug() << serial->readAll();
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    QApplication::processEvents();

    qDebug() << "fnc_openSerialPort()";
    fnc_openSerialPort();
    qDebug() << "writeData()";
    writeData();
    qDebug() << "readData()";
    readData();
    qDebug() << "fnc_closeSerialPort()";
    fnc_closeSerialPort();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serial;
}

void MainWindow::fnc_openSerialPort(){


    serial->setPortName("com5");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::HardwareControl);

    //QCoreApplication::connect(serial, &QSerialPort::readyRead, &onRead);

    //serial->open(QIODevice::ReadWrite);
    if(serial->isOpen()){
        serial->close();
    } else if(serial->open(QIODevice::ReadWrite)){
        qDebug() << "- Port opened";
    } else {
        qDebug() << "- Open error: " << serial->errorString();
    }

    while(serial->DataTerminalReadySignal == false){}
    while(serial->RequestToSendSignal == false){}
}

void MainWindow::fnc_closeSerialPort(){
    if(serial->isOpen()){
        serial->close();
        qDebug() << "- Port closed";
    }
}

void MainWindow::writeData(){

    if(serial->isOpen()){
        uint8_t bytes[] = {0x06, 0x02, 0x48, 0x65, 0x6C, 0x6C, 0x6F};
        serial->write((char*)bytes, sizeof(bytes));
        for(int i = 0; i < (int)sizeof(bytes); i++){
            qDebug("- 0x%02X",bytes[i]);
        }
        if (serial->waitForBytesWritten(100)){
            qDebug() << "- Writing complete";
        } else {
            qDebug() << "- Writing failed";
        }
    } else {
        qDebug() << "- Write error: " << serial->errorString();
    }
}

void MainWindow::readData(){
    if(serial->waitForReadyRead(5000)){
        QByteArray data = serial->readAll();

        qDebug() << "-" << data.toHex();
        qDebug() << "-" << data;
    } else {
        qDebug() << "-" << serial->errorString();
    }
}
