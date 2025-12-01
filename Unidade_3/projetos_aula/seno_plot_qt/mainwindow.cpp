#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
        ui->horizontalSlider_amplitude,
        SIGNAL(valueChanged(int)),
        ui->widget,
        SLOT(setAmplitude(int))
        );

    connect(
        ui->horizontalSlider_frequencia,
        SIGNAL(valueChanged(int)),
        ui->widget,
        SLOT(setFrequencia(int))
        );

    connect(
        ui->horizontalSlider_velocidade,
        SIGNAL(valueChanged(int)),
        ui->widget,
        SLOT(setVelocidade(int))
        );

    connect(
        ui->pushButton_reset,
        SIGNAL(clicked(bool)),
        ui->widget,
        SLOT(resetValores())
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}
