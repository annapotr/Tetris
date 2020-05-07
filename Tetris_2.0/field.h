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
#include <game.h>
#include <QLabel>

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

    bool getCell(std::pair<int, int> coords);
    void setCell(std::pair<int, int> coords, QPixmap pix);
    int getScore();
    gameStates getState();

    void printFieldTmp() const;

    void checkRow();
    void calculateScore(int cnt);
    void fill(QPixmap pix);
    bool doCollision();
    Tetrimino *generateNext(QGraphicsScene *scene);
    Fallen *generateFallen(QGraphicsScene *scene);

    bool isEnd();

    Tetrimino *currentTetrimino;
    Fallen *currentFallen;

    QPixmap get(int x, int y);
    std::size_t getFIELD_Ht();
    std::size_t getFIELD_W();
    int getNextFigure();

    QLabel* _lf;
    void changeImage(int nextFigure);
    std::string ImgSrc[7] = {":/redBlockss.png",":/orangeBlocks.png",":/yellowBlockss.png",":/greenBlocks.png",":/blueBlockss.png",":/blueblueBlocks.png",":/pinkBlockss.png"};


private:
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;
    static const int START_POS = 3;

    gameStates gameState;
    int curLevel, score;
    int highestNotEmpty;
    int nowFigure = 0, nextFigure;
    std::array<std::array<QPixmap, FIELD_W>, FIELD_Ht + 1> _field;
};

#endif // FIELD_H
