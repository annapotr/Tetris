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
#include <QString>

class Tetrimino;
class Fallen;

extern unsigned int SEED;

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
    bool getCell(std::pair<int, int> coords) const;
    int getScore() const;
    gameStates getState();
    QPixmap get(int x, int y) const;
    std::size_t getFIELD_Ht() const;
    std::size_t getFIELD_W() const;


    void printFieldTmp() const;

    void checkRow(QGraphicsScene *scene);
    void calculateScore(int cnt);
    void addToScore(int num);
    void fill(QPixmap pix);
    bool doCollision();
    Tetrimino *generateNext(QGraphicsScene *scene);
    Fallen *generateFallen(QGraphicsScene *scene);
    void generateNextId();
    int levelUp();

    Tetrimino *currentTetrimino;
    Fallen *currentFallen;

    int getNextFigure();

    QLabel* score_;
    QLabel* level_;

    QLabel* _lf;
    void changeImage(int nextFigure);
    std::vector<QString> ImgSrc = {":/redBlockss.png",":/orangeBlocks.png",":/yellowBlockss.png",":/greenBlocks.png",":/blueBlockss.png",":/blueblueBlocks.png",":/pinkBlockss.png"};

    gameStates gameState;

    void updateField(int level,QGraphicsScene *scene);

private:
    static constexpr std::size_t FIELD_Ht = 20;
    static constexpr std::size_t FIELD_W = 10;
    static constexpr int START_POS = 4;

    int curLevel, score, highestNotEmpty, nextFigure, deleteRows;
    std::vector<std::vector<QPixmap>> _field;
};

#endif // FIELD_H
