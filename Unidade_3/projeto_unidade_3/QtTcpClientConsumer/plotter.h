#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QVector>
#include <QPoint>
// #include <iostream>
// #include <vector>

class Plotter : public QWidget
{
    Q_OBJECT

private:
    QVector<QPointF> vector_pointers;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setNewPoint(int t, float v);
    QPointF getLastPoint();

signals:
};

#endif // PLOTTER_H
