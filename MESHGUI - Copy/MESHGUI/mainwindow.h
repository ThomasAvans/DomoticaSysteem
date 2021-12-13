#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "startup.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Startup *w, QWidget *parent = nullptr);
    ~MainWindow();

    /// @brief adds a tile
    void addTile();

    /// @brief removes a tile
    void removeTile();

    QString passedCOM_Port;
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    Startup *startup;
};
#endif // MAINWINDOW_H
