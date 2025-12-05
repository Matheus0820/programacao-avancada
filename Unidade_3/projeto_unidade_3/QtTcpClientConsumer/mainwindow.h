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

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void timerEvent(QTimerEvent *event);
  void getData();
  void setReceive(bool receive);
  void setConnected(bool connected);

  
public slots:
  void tcpConnect();
  void tcpDisconnect();
  void setTrueReceive();
  void setFalseReceive();
  void setTiming(int timing);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
