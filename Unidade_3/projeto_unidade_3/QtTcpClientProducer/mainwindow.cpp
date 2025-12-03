#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
    // Inicializando valores
    submit = false;
    connected = false;
    min = 0;
    max = 1;
    timing = 1000;
    this->timerId = startTimer(timing);


    ui->setupUi(this);
    socket = new QTcpSocket(this);
    ui->labelStatus->setText("Initialized...");
    ui->labelStatus->setStyleSheet("color: grey");

    // Conexão botão 'Connect'
    connect(
      ui->button_connect,
      SIGNAL(clicked(bool)),
      this,
      SLOT(tcpConnect())
      );

    // Conexão botão 'Disconnect'
    connect(
      ui->button_disconnect,
      SIGNAL(clicked(bool)),
      this,
      SLOT(tcpDisconnect())
      );

    // Conexão atualiza 'min'
    connect(
      ui->horizontalSlider_min,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setMin(int))
      );

    // Conexão atualiza 'max'
    connect(
      ui->horizontalSlider_max,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setMax(int))
      );

    // Conexão botão 'Start'
    connect(
      ui->button_start,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setTrueSubmit())
      );

    // Conexão botão 'Stop'
    connect(
      ui->button_stop,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setFalseSubmit())
      );

    // Conexão atualiza 'timing'
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
        this->connected = true;
        ui->labelStatus->setText("Connected");
        ui->labelStatus->setStyleSheet("color: green");
        putMessage("Connected", QColor(0, 255, 0));

    }
    else{
        qDebug() << "Disconnected";
        this->connected = false;
        ui->labelStatus->setText("Disconnected");
        ui->labelStatus->setStyleSheet("color: red");
        putMessage("Disconnected", QColor(255, 0, 0));
    }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Disconnected";
    this->connected = false;
    ui->labelStatus->setText("Disconnected");
    ui->labelStatus->setStyleSheet("color: red");
    putMessage("Disconnected", QColor(255, 0, 0));

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

    if (connected) {
        this->submit = true;

        putMessage("Start sending...", QColor(0, 0, 255));
        ui->labelStatus->setText("Connected - Sending");
        ui->labelStatus->setStyleSheet("color: blue");
    }
}

void MainWindow::setFalseSubmit()
{
    if (connected) {
        this->submit = false;

        putMessage("Stop sending...", QColor(252, 75, 8));
        ui->labelStatus->setText("Connected - Not Sending");
        ui->labelStatus->setStyleSheet("color: orange");
    }
}

void MainWindow::setTiming(int timing)
{
    this->timing = timing * 1000;
    killTimer(this->timerId);
    this->timerId = startTimer(this->timing);
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " +
        QString::number(( min + (rand() % (max - min + 1))))+"\r\n";

    putMessage(str, ui->listWidget->palette().text().color());
    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str())
               << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(connected && submit) {
        putData();
        qDebug() << "Enviando em: " << this->timing << " ms";
    }
}

void MainWindow::putMessage(const QString &mensagem, const QColor &cor)
{
    QListWidgetItem *item = new QListWidgetItem(mensagem);

    // Setando cor
    QBrush brush(cor);
    item->setForeground(brush);

    // Adicionando item no listWidgets
    ui->listWidget->addItem(item);
}


MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}


