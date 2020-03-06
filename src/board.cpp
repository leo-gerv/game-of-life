#include "board.h"

Board::Board(int width, int height):
    width(width),
    height(height),
    currentMat(0)
{
    matrices = new QVector<QVector<bool> >*[2];
    matrices[0] = new QVector<QVector<bool> >(height, QVector<bool>(width, false));
    matrices[1] = new QVector<QVector<bool> >(height, QVector<bool>(width, false));
}

Board::~Board()
{
    matrices[0]->clear();
    delete matrices[0];
    matrices[1]->clear();
    delete matrices[1];
}

QVector<QVector<bool> >& Board::currentRound()
{
    QVector<QVector<bool> >* matrix = matrices[currentMat];
    return *matrix;
}

void Board::moveNext()
{
    QVector<QVector<bool> >* matrix = matrices[currentMat];

    QVector<QVector<bool> >* swapMatrix = matrices[currentMat^1];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int n = neighbours(x, y);

            if (n == 3) {
                (*swapMatrix)[y][x] = 1;
            }
            else if (n == 2 && (*matrix)[y][x]) {
                (*swapMatrix)[y][x] = 1;
            }
            else
                (*swapMatrix)[y][x] = 0;
        }
    }
    currentMat ^= 1;
}

int Board::neighbours(int &x, int &y)
{
    // To be optimized
    int r = 0;

    QVector<QVector<bool> >* matrix = matrices[currentMat];

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

void Board::setHeight(int value)
{
    for (int i = 0; i < 2; i++) {
        matrices[i]->resize(value);
        for (int k = height; k < value; k++) {
            (*matrices[i])[k] = QVector<bool>(width, false);
        }
    }
    height = value;
}

void Board::setWidth(int value)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < height; j++) {
            (*matrices[i])[j].resize(value);
            for (int k = width; k < value; k++)
                (*matrices[i])[j][k] = false;
        }
    }
    width = value;
}
