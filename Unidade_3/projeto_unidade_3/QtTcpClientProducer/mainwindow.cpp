#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
    submit = false;

    ui->setupUi(this);
    socket = new QTcpSocket(this);
    ui->labelStatus->setText("Initialized...");
    ui->labelStatus->setStyleSheet("color: grey");

  connect(ui->button_start,
          SIGNAL(clicked(bool)),
          this,
          SLOT(putData()));

  connect(
      ui->button_connect,
      SIGNAL(clicked(bool)),
      this,
      SLOT(tcpConnect())
      );

  connect(
      ui->horizontalSlider_min,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setMin(int))
      );

  connect(
      ui->horizontalSlider_max,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setMax(int))
      );

  connect(
      ui->button_start,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setTrueSubmit())
      );

  connect(
      ui->button_stop,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setFalseSubmit())
      );

  connect(
      ui->horizontalSlider_timing,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setTiming(int))
      );

}

void MainWindow::tcpConnect(){
    QString ip = ui->inputIp->text(); // Pegando valor digitado pelo usuário

    socket->connectToHost(ip,1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        ui->labelStatus->setText("Connected");
        ui->labelStatus->setStyleSheet("color: green");

    }
    else{
        qDebug() << "Disconnected";
        ui->labelStatus->setText("Disconnected");
        ui->labelStatus->setStyleSheet("color: red");
    }
}

void MainWindow::setMin(int min)
{
    this->min = min;
}

void MainWindow::setMax(int max)
{
    this->max = max;
}

void MainWindow::setTrueSubmit()
{
    this->submit = true;
}

void MainWindow::setFalseSubmit()
{
    this->submit = false;
}

void MainWindow::setTiming(int timing)
{
    this->timing = timing;
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " +
        QString::number(( min + (rand() % (max - min + 1))))+"\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str())
               << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(submit) {
        putData();
    }
}
