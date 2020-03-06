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

void Board::moveNext()
{
}

int Board::neighbours(int &x, int &y)
{
    // To be optimized
    int r = 0;

    if (x) {
        r += (*matrix)[y][x-1]; // Left neighbour
        if (y)
            r += (*matrix)[y-1][x-1]; // Top left neighbour
    }

    if (y) {
        r += (*matrix)[y-1][x]; // Top neighbour
        if (x < width - 1)
            r += (*matrix)[y-1][x+1]; // Top right neighbour
    }

    if (x < width - 1) {
        r += (*matrix)[y][x+1]; // Right neighbour
        if (y < height - 1)
            r += (*matrix)[y+1][x+1]; // Bottom right neighbour
    }

    if (y < height - 1) {
        r += (*matrix)[y+1][x]; // Bottom neighbour
        if (x)
            r += (*matrix)[y+1][x-1]; // Bottom left neighbour
    }

    return r;
}
