#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(Startup *w, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *Sensors = new QListWidgetItem("Sensors");
    ui->listWidget->addItem(Sensors);
    QListWidgetItem *Actuators = new QListWidgetItem("Actuators");
    ui->listWidget->addItem(Actuators);
    QListWidgetItem *allItem = new QListWidgetItem("All");
    ui->listWidget->addItem(allItem);
    startup = w;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTile(){
//QBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->gridLayout->layout());

//QString buttonText = tr("Button: #%1").arg(layout->count());
  //  QPushButton* button = new QPushButton(ui->gridLayout->widget());
    //layout->insertWidget(0, button);


}

void MainWindow::removeTile(){

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{

  if(ui->listWidget->currentItem()->text() != "Actuators")
  {


      if(ui->listWidget->currentItem()->text() == "Sensors")
       {
          ui->Actuator->setVisible(false);
          ui->Sensor->setVisible(true);
       }
      else if(ui->listWidget->currentItem()->text() == "All")
       {
          ui->Sensor->setVisible(true);
          ui->Actuator->setVisible(true);
       }



  } else if(ui->listWidget->currentItem()->text() != "Sensors")
    {

        if(ui->listWidget->currentItem()->text() == "Actuators")
         {
            ui->Actuator->setVisible(true);
            ui->Sensor->setVisible(false);
         }
        else if(ui->listWidget->currentItem()->text() == "All")
         {
            ui->Sensor->setVisible(true);
            ui->Actuator->setVisible(true);
         }
    }
}



  // QMessageBox::information(this, "title", ui->listWidget->currentItem()->text());
