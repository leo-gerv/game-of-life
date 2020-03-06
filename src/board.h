#ifndef BOARD_H
#define BOARD_H

#include <QVector>

class Board
{
public:
    Board(int width, int height);
    ~Board();

    QVector<QVector<bool> >& currentRound();

    void moveNext();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    int width, height;
    QVector<QVector<bool> > *matrix, *swapMatrix;

    int neighbours(int &x, int &y);
};

#endif // BOARD_H
