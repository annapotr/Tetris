#ifndef FIELD_H
#define FIELD_H

#include "figures.h"
#include <QObject>
#include <QColor>
#include <iosfwd>
#include <vector>
#include <utility>

class Tetrimino;

enum class gameStates {
    INPROCESS,
    GAMEOVER,
    PAUSED
};

extern std::vector<int> points;

class Field {
public:
    explicit Field(int level);

    bool getCell(std::pair<int, int> coords);
    void setCell(std::pair<int, int> coords, QColor color);
    int getScore();
    gameStates getState();

    void printFieldTmp() const;

    void checkRow();
    void calculateScore(int cnt);
    void fill(QColor color);
    bool doCollision();
    Tetrimino *generateNext(QGraphicsScene *scene);

    Tetrimino *currentTetrimino;

private:
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;
    static const int START_POS = 3;

    gameStates gameState;
    int curLevel, score;
    int highestNotEmpty;
    std::array<std::array<QColor, FIELD_W>, FIELD_Ht + 1> _field;
};

#endif // FIELD_H
