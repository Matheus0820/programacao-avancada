#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool receive, connected;
    int timing; // Em milisegundos
    int timerId = -1;
    QString ipGetData;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void timerEvent(QTimerEvent *event);
  void getData();
  void setReceive(bool receive);
  void setConnected(bool connected);
  void addItemListWidget(const QString ip);
  void setIpGetData(const QString ipGetData);

  
public slots:
  void tcpConnect();
  void tcpDisconnect();
  void setTrueReceive();
  void setFalseReceive();
  void setTiming(int timing);
  void selectedItem();
  void updateIp();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;

};

#endif // MAINWINDOW_H
