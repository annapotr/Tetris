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
    QPixmap pix(":/red_block.png");

    _field.resize(FIELD_Ht + 2, std::vector<QPixmap>(FIELD_W + 2));

    for (size_t i = 0; i <= FIELD_Ht; i++) {
        std::fill(_field[i].begin() + 1, _field[i].end() - 1, QPixmap());
        _field[i][0] = pix;
        _field[i][FIELD_W + 1] = pix;
    }
    std::fill(_field[FIELD_Ht + 1].begin() + 1, _field[FIELD_Ht + 1].end() - 1, pix);
    generateNextId();
}

void Field::updateField(int level,QGraphicsScene *scene) {
    gameState = gameStates::INPROCESS, curLevel = level , score = 0 , highestNotEmpty = FIELD_Ht;
    _blackImg->setStyleSheet("background: rgba(255, 255, 255, 0)");
    for (size_t i = 0; i <= FIELD_Ht; i++) {
        std::fill(_field[i].begin() + 1, _field[i].end() - 1, QPixmap());
    }
    QPixmap pix(":/red_block.png");
    std::fill(_field[FIELD_Ht + 1].begin() + 1, _field[FIELD_Ht + 1].end() - 1, pix);

    generateNextId();
}

void Field::printFieldTmp() const {
    for (size_t i = 1; i <= FIELD_Ht; i++) {
        for (size_t j = 1; j <= FIELD_W; j++) {
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
    QPixmap pix(":/red_block.png");
    int cnt = 0;
    for (size_t i = highestNotEmpty; i <= FIELD_Ht; i++) {
        bool row = true;
        for (auto &cell: _field[i]) {
            row &= !(cell.isNull());
        }
        if (row) {
            cnt++;
            std::fill(_field[i].begin() + 1, _field[i].end() - 1, QPixmap());
            for (int j = i - 1; j >= highestNotEmpty; j--) {
                _field[j + 1] = move(_field[j]);
            }
            std::fill(_field[i].begin() + 1, _field[i].end() - 1, QPixmap());
            highestNotEmpty++;
            calculateScore(cnt);
        }
    }
}

bool Field::doCollision() {
   bool hasFilled = false;
   for (auto &item: currentTetrimino->_blocks) {
       hasFilled |= getCell({static_cast<int>(currentTetrimino->topLeftCorner.ry() + item.first + 1),
                             static_cast<int>(currentTetrimino->topLeftCorner.rx() + item.second)});

       /*if (hasFilled) {
          qDebug() << "collision Y: " << (currentTetrimino->topLeftCorner.ry()+item.first + 1) << " collision X: " << (currentTetrimino->topLeftCorner.rx()+item.second);
       }*/

   }
   return hasFilled;
}

bool Field::banRotate() {
    bool banRotate = false;
    for (auto &item: currentTetrimino->_blocks) {
        banRotate |= getCell({static_cast<int>(currentTetrimino->topLeftCorner.ry() + item.first),
                              static_cast<int>(currentTetrimino->topLeftCorner.rx() + item.second)});
    }
    return banRotate;
}

void Field::fill(QPixmap pix) {
    for (auto &item: currentTetrimino->_blocks) {
        int row = currentTetrimino->topLeftCorner.ry() + item.first;
        int col = currentTetrimino->topLeftCorner.rx() + item.second;
        setCell({row, col}, pix);
        if (highestNotEmpty > row) highestNotEmpty = row;
    }
}

void Field::generateNextId() {
    nextFigure = getRand() % tetriminoesInit.size();
}

Tetrimino *Field::generateNext(QGraphicsScene *scene) {
    Tetrimino *F = new Tetrimino(tetriminoesInit[nextFigure], static_cast<tetriminoes>(nextFigure), this, scene);
    F->setCoordinates(START_POS);
    generateNextId();
    changeImage(nextFigure);
    return F;
}

Fallen *Field::generateFallen(QGraphicsScene *scene) {
    Fallen *F = new Fallen(this, scene);
    return F;
}

bool Field::getCell(std::pair<int, int> coords) {
    if (coords.first < 0 || coords.first > (int)FIELD_Ht) return true;
    if (coords.second < 1 || coords.second > (int)FIELD_W) return true;
    return !(_field[coords.first][coords.second].isNull());
}

gameStates Field::getState() {
    if (highestNotEmpty <= 1) gameState = gameStates::GAMEOVER;
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

void Field::changeImage(int nextFigure) {
    QPixmap pix(ImgSrc[nextFigure].c_str());
    _lf->setPixmap(pix);
}

void Field::changeBlackImg() {
    QLabel* bblackImg = new QLabel();
    bblackImg->resize(50,50);
    bblackImg->setStyleSheet("background: rgba(188, 188, 188, 92)");
    _blackImg = bblackImg;
}


