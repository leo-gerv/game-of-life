#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>

#include <QRect>

#include <QMouseEvent>

#include <QDebug>

#include "board.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(Board& board, QWidget *parent = 0);

    Board board;
    bool displayBorders;

    QBrush borderBrush, aliveBrush, deadBrush;
    
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

    int cellWidth, cellHeight;

signals:
    
public slots:
    
};

#endif // BOARDWIDGET_H
