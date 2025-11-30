#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

#define PI 3.1415 // Valor aproximado de Pi que sera usado para plotar o seno

Plotter::Plotter(QWidget *parent): QWidget{parent} {
    fase = 0;
    amp = 1;
    freq = 1;
    vel = 0;
}

void Plotter::paintEvent(QPaintEvent *event) {
    // Definindo objetos que auxiliaram na pintura da tela
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    // Definindo cor da escova (brush) como amarela
    brush.setColor(QColor(255, 255, 100));
    brush.setStyle(Qt::SolidPattern);

    // Definindo cor da caneta
    pen.setColor(QColor(0, 0, 255));
    pen.setWidth(3);

    // Informando quem é o brush atual
    painter.setBrush(brush);

    // Informando quem é a caneta
    painter.setPen(pen);

    // Desenhando um retangulo que sobre a tela inteira
    painter.drawRect(0, 0, width(), height());



}
