#include "field.h"
#include "figures.h"
#include <iostream>
#include <array>
#include <utility>
#include <QDebug>
#include <QPainter>
#include <QAbstractScrollArea>
#include <random>

unsigned int SEED =  std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 getRand(SEED);

using std::move;
using std::size_t;

std::vector<int> points = {40, 100, 300, 1200};

Field::Field(int level) :
    gameState(gameStates::INPROCESS), curLevel(level), score(0), highestNotEmpty(FIELD_Ht) {
    for (size_t i = 0; i <= FIELD_Ht; i++) {
        _field[i].fill(QPixmap());
    }
    QPixmap pix(":/red_block.png");
    _field[FIELD_Ht + 1].fill(pix);
}

void Field::printFieldTmp() const {
    for (size_t i = 0; i <= FIELD_Ht; i++) {
        for (size_t j = 0; j < FIELD_W; j++) {
            std::cout << !(_field[i][j].isNull()) << ' ';
        }
        std::cout << '\n' ;
    }
    std::cout << '\n';
}


void Field::calculateScore(int cnt) {
    if (cnt > 4) cnt = 4;
    score += points[cnt - 1] * (curLevel + 1);
}

void Field::checkRow() {
    int cnt = 0;
    for (size_t i = highestNotEmpty; i <= FIELD_Ht; i++) {
        bool row = true;
        for (auto &cell: _field[i]) {
            row &= !(cell.isNull());
        }
        if (row) {
            cnt++;
            _field[i].fill(QPixmap());
            for (int j = i - 1; j >= highestNotEmpty; j--) {
                _field[j + 1] = move(_field[j]);
            }
            _field[highestNotEmpty].fill(QPixmap());
            highestNotEmpty++;
            calculateScore(cnt);
        }
    }
}

bool Field::doCollision() {
   bool hasFilled = false;
   for (auto &item: currentTetrimino->_blocks) {
       hasFilled |= getCell({(int)(currentTetrimino->topLeftCorner.ry() + item.first + 1),
                             (int)(currentTetrimino->topLeftCorner.rx() + item.second)});

       /*if (hasFilled) {
          qDebug() << "collision Y: " << (currentTetrimino->topLeftCorner.ry()+item.first + 1) << " collision X: " << (currentTetrimino->topLeftCorner.rx()+item.second);
       }*/

   }
   return hasFilled;
}

void Field::fill(QPixmap pix) {
    for (auto &item: currentTetrimino->_blocks) {
        int row = currentTetrimino->topLeftCorner.ry() + item.first;
        int col = currentTetrimino->topLeftCorner.rx() + item.second;
        //int col = START_POS + item.second;
        setCell({row, col}, pix);
        if (highestNotEmpty > row) highestNotEmpty = row;
    }
}

//should divide generateNext into 2 functions (random type & figure + field)

Tetrimino *Field::generateNext(QGraphicsScene *scene) {
    //if (getState() == gameStates::GAMEOVER) return;
    nextFigure = getRand() % tetriminoesInit.size(); //для отображения следующей фигурки, strange constant
    Tetrimino *F = new Tetrimino(tetriminoesInit[nowFigure], static_cast<tetriminoes>(nowFigure), this, scene);
    F->setCoordinates(START_POS); //перенести куда-нибудь!
    nowFigure = nextFigure;//nextFigure нигде больше не хранится => local var?, For what???? Think about it! Is both necessary?
    return F;
}

int Field::getNextFigure(){
    return nextFigure;
}

Fallen *Field::generateFallen(QGraphicsScene *scene) {
    Fallen *F = new Fallen(this, scene);
    return F;
}

bool Field::getCell(std::pair<int, int> coords) {
    return !(_field[coords.first][coords.second].isNull());
}

gameStates Field::getState() {
    if (highestNotEmpty <= 1) gameState = gameStates::GAMEOVER;
    // PAUSED;
    return gameState;
}

void Field::setCell(std::pair<int, int> coords, QPixmap pix) {
    _field[coords.first][coords.second] = QPixmap(pix);
}

int Field::getScore() {
    return score;
}

QPixmap Field::get(int x, int y) {
    return _field[x][y];
}

std::size_t Field::getFIELD_Ht(){
    return FIELD_Ht;
}

std::size_t Field::getFIELD_W(){
    return FIELD_W;
}


