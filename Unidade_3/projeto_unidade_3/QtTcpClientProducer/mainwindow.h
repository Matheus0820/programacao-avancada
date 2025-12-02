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
    int min, max;
    bool submit, connected;
    int timing;
    int timerId = -1;
    Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void putData();
  void timerEvent(QTimerEvent *event);
  bool getSubmit();
  void setConnected(bool connected);
  bool getConnected();

public slots:
    void tcpConnect();
    void tcpDisconnect();
    void setMin(int min);
    void setMax(int max);
    void setTrueSubmit();
    void setFalseSubmit();
    void setTiming(int timing);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
