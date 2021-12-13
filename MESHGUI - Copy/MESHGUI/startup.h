#ifndef STARTUP_H
#define STARTUP_H

#include <QDialog>
class MainWindow;
namespace Ui {
class Startup;
}

class Startup : public QDialog
{
    Q_OBJECT

public:
    explicit Startup(QWidget *parent = nullptr);
    ~Startup();

    QString COM_Port;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Startup *ui;
    MainWindow *_MainWindow;
};

#endif // STARTUP_H
