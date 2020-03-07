#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    board(Board(20, 20)),
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

void MainWindow::on_colSpin_valueChanged(int value)
{
    board.setHeight(value);
    boardWidget->repaint();
}

void MainWindow::on_rowSpin_valueChanged(int value)
{
    board.setWidth(value);
    boardWidget->repaint();
}

void MainWindow::on_breed_clicked()
{
    board.setAll(true);
    boardWidget->repaint();
}

void MainWindow::on_kill_clicked()
{
    board.setAll(false);
    boardWidget->repaint();
}

void MainWindow::on_exportBoard_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Export the current board"); // Blocks the loop, no need to stop the timer
    if (path.isEmpty())
        return;
    if (!board.saveToFile(path))
        QMessageBox::critical(this, "Error", "Could not write the file. Please check your permissions.");
}

void MainWindow::on_importBoard_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Import a board");
    if (path.isEmpty())
        return;
    if (!board.loadFromFile(path))
        QMessageBox::critical(this, "Error", "Unable to import the board. It may be corrupted or missing permissions.");
    ui->rowSpin->setValue(board.getWidth());
    ui->colSpin->setValue(board.getHeight());
    boardWidget->repaint();
}
