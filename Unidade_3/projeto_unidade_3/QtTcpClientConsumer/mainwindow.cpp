#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    // Iniciando valores das variáveis
    timing = 1000;
    connected = false;
    receive = false;
    ipGetData = "127.0.0.1";


    ui->setupUi(this);
    socket = new QTcpSocket(this);
    this->timerId = startTimer(1000); // Tempo padrão de recepção de dados é 1 segundo
    ui->labelStatus->setText("Initialized...");
    ui->labelStatus->setStyleSheet("color: grey");
    ui->pushButtonUpdate->setDisabled(true);
    ui->pushButtonStart->setDisabled(true);
    ui->pushButtonStop->setDisabled(true);

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

  // Connect do botão Start
  connect(
      ui->pushButtonStart,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setTrueReceive())
      );

  // Connect do botão Stop
  connect(
      ui->pushButtonStop,
      SIGNAL(clicked(bool)),
      this,
      SLOT(setFalseReceive())
      );

  // Connect do Select
  connect(
      ui->listWidget,
      SIGNAL(itemSelectionChanged()),
      this,
      SLOT(selectedItem())
      );

  // Connect do botão Update
  connect(
      ui->pushButtonUpdate,
      SIGNAL(clicked(bool)),
      this,
      SLOT(updateIp())
      );

  // Connect do Timing
  connect(
      ui->horizontalSliderTiming,
      SIGNAL(valueChanged(int)),
      this,
      SLOT(setTiming(int))
      );

}

void MainWindow::tcpConnect(){
    QString ip = ui->lineEditIp->text();
    qDebug() << "IP: " << ip;

  socket->connectToHost(ip,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->labelStatus->setText("Connect");
    ui->labelStatus->setStyleSheet("color: green");
    setConnected(true);
    addItemListWidget(ip);
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
    if (connected) {
        setReceive(true);
        ui->labelStatus->setText("Connected - Receiving data");
        ui->labelStatus->setStyleSheet("color: blue");
    }
}

void MainWindow::setFalseReceive()
{
    if (connected) {
        setReceive(false);
        ui->labelStatus->setText("Connected - Not receiving data");
        ui->labelStatus->setStyleSheet("color: #FC4B08");
    }

}

void MainWindow::setTiming(int timing)
{
    this->timing = timing * 1000; // Segundos para milisegundos
    killTimer(timerId);
    this->timerId = startTimer(this->timing);
}

void MainWindow::selectedItem()
{
    ui->pushButtonUpdate->setDisabled(false);
}

void MainWindow::updateIp()
{
    QListWidgetItem *item_select = ui->listWidget->currentItem();
    setIpGetData(QString(item_select->text()));
    ui->pushButtonStart->setDisabled(false);
    ui->pushButtonStop->setDisabled(false);
}

void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  qDebug() << "to get data...";
  QString ipGet; // = "get 127.0.0.1 1\r\n";
  ipGet = "get " + ipGetData + " 1\r\n";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write(ipGet.toUtf8());
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

          // Definindo base de tempo
          int base_temp = this->timing/1000;
          ui->widget->setNewPoint(base_temp, str.toFloat());

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

void MainWindow::addItemListWidget(const QString ip)
{
    QListWidgetItem *item = new QListWidgetItem(ip);
    ui->listWidget->addItem(item);

}

void MainWindow::setIpGetData(const QString ipGetData)
{
    this->ipGetData = ipGetData;
}

MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    qDebug() << "Tempo de recepção dos dados: " << this->timing / 1000 << "s";
    if(connected && receive) {
        getData();
        qDebug() << "Recebendo dados";
    }
}
