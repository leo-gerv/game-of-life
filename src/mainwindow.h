#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>

#include <QGridLayout>

#include <QTimer>

#include "board.h"
#include "boardwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private:
    Ui::MainWindow *ui;
    Board board;
    BoardWidget *boardWidget;

    QGridLayout *layout;

    QTimer *timer;

    bool manualChange;

private slots:
    void on_startButton_clicked();
    void on_doubleSpinBox_valueChanged(double);
    void on_horizontalSlider_valueChanged(int);
    void on_colSpin_valueChanged(int);
    void on_rowSpin_valueChanged(int);
    void reqNextRound();
};

#endif // MAINWINDOW_H
