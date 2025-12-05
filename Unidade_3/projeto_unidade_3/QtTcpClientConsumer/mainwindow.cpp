#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);

    // Connect do botão Connect
  connect(
      ui->pushButtonConnect,
      SIGNAL(clicked(bool)),
      this,
      SLOT(tcpConnect())
      );
  // Connect do botão Disconnect
  connect(
      ui->pushButtonDisconnect,
      SIGNAL(clicked(bool)),
      this,
      SLOT(tcpDisconnect())
      );

  // connect(ui->pushButtonGet,
  //         SIGNAL(clicked(bool)),
  //         this,
  //         SLOT(getData()));
}

void MainWindow::tcpConnect(){
    QString ip = ui->lineEditIp->text();
    qDebug() << "IP: " << ip;

  socket->connectToHost(ip,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->labelStatus->setText("Connect");
    ui->labelStatus->setStyleSheet("color: green");
  }
  else{
      qDebug() << "Disconnected";
      ui->labelStatus->setText("Disconnect");
      ui->labelStatus->setStyleSheet("color: red");

  }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Disconnect";
    ui->labelStatus->setText("Disconnect");
    ui->labelStatus->setStyleSheet("color: red");
}

void MainWindow::setTrueReceive()
{
    setReceive(true);
}

void MainWindow::setFalseReceive()
{
    setReceive(false);
}

void MainWindow::setTiming(int timing)
{
    this->timing = timing * 1000; // Segundos para milisegundos
    killTimer(timerId);
    this->timerId = startTimer(this->timing);
}

void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write("get 127.0.0.1 5\r\n");
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }
}

void MainWindow::setReceive(bool receive)
{
    this->receive = receive;
}

void MainWindow::setConnected(bool connected)
{
    this->connected = connected;
}



MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(connected && receive) {
        getData();
        qDebug() << "Recebendo dados";
    }
}
