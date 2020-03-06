#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QDebug>

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
    int width, height, currentMat;
    QVector<QVector<bool> > **matrices;

    int neighbours(int &x, int &y);
};

#endif // BOARD_H
