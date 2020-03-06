#ifndef BOARD_H
#define BOARD_H

#include <QVector>

class Board
{
public:
    Board(int width, int height);
    ~Board();

    QVector<QVector<bool> >& currentRound();

protected:
    int width, height;
    QVector<QVector<bool> > *matrix, *swapMatrix;
};

#endif // BOARD_H
