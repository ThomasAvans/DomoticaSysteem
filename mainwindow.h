#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void fnc_openSerialPort();
    void fnc_closeSerialPort();
    void writeData();
    void readData();
private:
    Ui::MainWindow *ui;

//    QSerialPort *serial;

};
#endif // MAINWINDOW_H
