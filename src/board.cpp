#include "board.h"

Board::Board(int width, int height):
    width(width),
    height(height),
    matrix(new QVector<QVector<bool> >(height, QVector<bool>(width, false))),
    swapMatrix(new QVector<QVector<bool> >(height, QVector<bool>(width, false)))
{
}

Board::~Board()
{
    matrix->clear();
    delete matrix;
    swapMatrix->clear();
    delete swapMatrix;
}

QVector<QVector<bool> >& Board::currentRound()
{
    return *matrix;
}
