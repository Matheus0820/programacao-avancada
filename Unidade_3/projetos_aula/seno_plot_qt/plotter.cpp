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

    // Ativando o temporizador
    startTimer(50);
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

    // Pintando uma linha no meio da tela
    painter.drawLine(0, height()/2, width(), height()/2);

    /* Plotando o Seno */
    // Mudando a cor da caneta para preto
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);


    // Variáveis auxíliares:
    int x0, y0, x1, y1;
    x0 = 0; // Lado esquedo da tela
    y0 = height()/2; // Metade da tela

    float porc_amplitude = amp;
    float frequencia = freq; // Frequência em Hz

    // Laço que vai atualizar o valor de y1 em função do seno
    for(x1 = 1; x1 < width(); x1++) {
        y1 = height()/2 - (height()/2) * porc_amplitude * sin(fase + (frequencia * 2 * PI * x1)/width());

        // Desenhando o ponto (x1, y1)
        painter.drawLine(x0, y0, x1, y1);

        // Atualizando os valores de x0 e y0 para o velores atuais de x1 e y1
        x0 = x1;
        y0 = y1;
    }

}

void Plotter::timerEvent(QTimerEvent *event)
{
    fase = fase + vel;
    repaint();

}

void Plotter::setAmplitude(int amp) {
    this->amp = amp/100.0;
    repaint();
}

void Plotter::setFrequencia(int freq)
{
    this->freq = freq;
    repaint();
}

void Plotter::setVelocidade(int vel)
{
    this->vel = vel;
    repaint();
}

void Plotter::resetValores()
{
    fase = 0;
    amp = 1;
    freq = 1;
    vel = 0;
    repaint();
}
