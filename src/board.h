#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QDebug>

#include <QFile>
#include <QTextStream>
#include <QStringList>

class Board
{
public:
    Board(int width, int height);
    ~Board();

    QVector<QVector<bool> >& currentRound();

    void moveNext();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setWidth(int value);
    void setHeight(int value);

    void setAll(bool value);

    bool saveToFile(const QString &fileName);
    bool loadFromFile(const QString &fileName);

protected:
    int width, height, currentMat;
    QVector<QVector<bool> > **matrices;

    int neighbours(int &x, int &y);
};

#endif // BOARD_H
