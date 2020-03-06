#include "boardwidget.h"

BoardWidget::BoardWidget(Board *board, QWidget *parent) :
    QWidget(parent),
    board(board),
    displayBorders(true),
    borderBrush(QBrush(Qt::gray)),
    aliveBrush(QBrush(Qt::black)),
    deadBrush(QBrush(Qt::white))
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void BoardWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QVector<QVector<bool> > *matrix = &board->currentRound();

    cellHeight = height()/board->getHeight();
    cellWidth = width()/board->getWidth();

    for (int y = 0; y < board->getHeight(); y++) {
        for (int x = 0; x < board->getWidth(); x++) {
            QRect cell((x * width())/board->getWidth(), (y * height())/board->getHeight(), cellWidth, cellHeight);

            if ((*matrix)[y][x])
                p.fillRect(cell, aliveBrush);
            else
                p.fillRect(cell, deadBrush);

            p.setPen(QPen(borderBrush, 0.5));
            p.drawRect(cell);
        }
    }
}

void BoardWidget::mousePressEvent(QMouseEvent *e)
{
    QPoint pos = e->pos();
    board->currentRound()[pos.y() / cellHeight][pos.x() / cellWidth] ^= 1;
    update();
}
