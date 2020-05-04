#ifndef FIELD_H
#define FIELD_H
#include "QGraphicsItem"
#include "figures.h"
#include <QObject>
#include <QColor>
#include <iosfwd>
#include <vector>
#include <utility>
#include <array>
#include <QWidget>
#include <QPainter>
#include <fallen.h>

class Tetrimino;

class Fallen;

enum class gameStates {
    INPROCESS,
    GAMEOVER,
    PAUSED
};

extern std::vector<int> points;

class Field {
public:
    explicit Field(int level);

    void setCell(std::pair<int, int> coords, QPixmap pix);
    bool getCell(std::pair<int, int> coords);
    int getScore();
    gameStates getState();
    QPixmap get(int x, int y);
    std::size_t getFIELD_Ht();
    std::size_t getFIELD_W();
    //int getNextFigure();

    void printFieldTmp() const;

    void checkRow();
    void calculateScore(int cnt);
    void fill(QPixmap pix);
    bool doCollision();
    Tetrimino *generateNext(QGraphicsScene *scene);
    Fallen *generateFallen(QGraphicsScene *scene);
    void generateNextId();

    Tetrimino *currentTetrimino;
    Fallen *currentFallen;

private:
    static constexpr std::size_t FIELD_Ht = 20;
    static constexpr std::size_t FIELD_W = 10;
    static constexpr int START_POS = 4;

    gameStates gameState;
    int curLevel, score, highestNotEmpty, nextFigure;
    //std::array<std::array<QPixmap, FIELD_W + 2>, FIELD_Ht + 2> _field;
    std::vector<std::vector<QPixmap>> _field;
};

#endif // FIELD_H
