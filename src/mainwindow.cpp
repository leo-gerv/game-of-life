#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    board(Board(8, 8)),
    boardWidget(new BoardWidget(&board, this)),
    timer(new QTimer(this)),
    manualChange(true)
{
    ui->setupUi(this);

    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::reqNextRound);

    layout = new QGridLayout(ui->centralWidget);

    layout->addWidget(boardWidget, 0, 0);
    layout->addWidget(ui->groupBox, 0, 1);

    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (timer->isActive()) {
        ui->startButton->setText("Start");
        timer->stop();
    }
    else {
        ui->startButton->setText("Stop");
        timer->start();
    }
}

void MainWindow::on_doubleSpinBox_valueChanged(double value)
{
    if (manualChange)
        ui->horizontalSlider->setValue((value * ui->horizontalSlider->maximum()) / ui->doubleSpinBox->maximum());
    manualChange ^= 1;
    timer->setInterval(1000 / ui->doubleSpinBox->value());
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (manualChange)
        ui->doubleSpinBox->setValue(((double) value * ui->doubleSpinBox->maximum()) / (double) ui->horizontalSlider->maximum());
    manualChange ^= 1;
    timer->setInterval(1000 / ui->doubleSpinBox->value());
}

void MainWindow::reqNextRound()
{
    board.moveNext();
    boardWidget->repaint();
}
