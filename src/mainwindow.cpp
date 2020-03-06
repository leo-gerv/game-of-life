#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    board(Board(20, 20)),
    boardWidget(new BoardWidget(board, this))
{
    ui->setupUi(this);

    layout = new QGridLayout(ui->centralWidget);

    layout->addWidget(boardWidget);

    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
