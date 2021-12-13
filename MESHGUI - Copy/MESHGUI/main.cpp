


#include "mainwindow.h"
#include "startup.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    //create the application and the main window
    QApplication app(argc, argv);
    Startup w;




    //open qss file
    qDebug() << QDir::currentPath();
    QFile file("../MESHGUI/stylesheet/styleSheet.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    app.setStyleSheet(styleSheet);

    //run
    w.show();

    return app.exec();

}


