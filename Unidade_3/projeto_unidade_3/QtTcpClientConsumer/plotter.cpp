#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    // Definindo valores das variáveis
    vector_pointers.append(QPointF(0.0, height()));
    vector_pointers.append(QPointF(0.0, height()));
}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    // Definindo cor do brush como o brush atual
    brush.setColor(QColor(255, 255, 100));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    // Definindo cor da pen e como a pen atual
    pen.setColor(QColor(0, 0, 255));
    pen.setWidth(2);
    painter.setPen(pen);

    // Definindo cor da tela
    painter.drawRect(0, 0, width(), height());

    // Pintando pontos na tela
    float offSetX = 0;
    if (vector_pointers.last().x() > width()*0.80) {
        offSetX = vector_pointers.last().x() - (width() * 0.80);
    }

    for (int i = 1; i < vector_pointers.size(); i++) {
        QPointF p0 = vector_pointers[i - 1];
        QPointF p1 = vector_pointers[i];


        float x0 = (p0.x() - offSetX);
        float y0 = p0.y();
        float x1 = (p1.x() - offSetX);
        float y1 = p1.y();

        // qDebug() << "x0 = " << x0 << " y0 = " << y0;
        // qDebug() << "x1 = " << x1 << " y1 = " << y1;


        painter.drawLine(x0, y0, x1, y1);
    }

}


void Plotter::setNewPoint(int t, float v)
{
    // Normalizando os valores recebidos
    float x = vector_pointers.isEmpty() ? 0 : vector_pointers.last().x() + ( t * 10.0);
    float y = height() - ((v * height())/100);

    vector_pointers.append(QPoint(x, y));
    repaint();
}

QPointF Plotter::getLastPoint()
{
    return vector_pointers.last();
}
