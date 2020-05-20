#include "field.h"
#include "figures.h"
#include <iostream>
#include <array>
#include <utility>
#include <QDebug>
#include <QPainter>
#include <QAbstractScrollArea>
#include <random>

using std::move;
using std::size_t;

constexpr int Tetris = 4;

unsigned int SEED =  std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 getRand(SEED);

std::vector<int> points = {40, 100, 300, 1200};
std::vector<size_t> possibleSize = {1, 3, 5};

Field::Field(int level) :
    gameState(gameStates::INPROCESS), curLevel(level), score(0), highestNotEmpty(FIELD_Ht), deleteRows(0) {
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

void Field::updateField(int level, QGraphicsScene *scene) {
    gameState = gameStates::INPROCESS, curLevel = level, deleteRows = 0, score = 0 , highestNotEmpty = FIELD_Ht;
    tetriminoesInit.resize(7);
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
    if (cnt > Tetris) cnt = Tetris;
    score += points[cnt - 1] * (curLevel + 1);
    score_->setNum(score);
}

void Field::addToScore(int num) {
    score += num;
    score_->setNum(score);
}

void Field::checkRow(QGraphicsScene *scene) {
    int cnt = 0;
    for (size_t row = highestNotEmpty; row <= FIELD_Ht; row++) {
        bool fullRow = true;
        for (auto &cell: _field[row]) fullRow &= !(cell.isNull());

        if (fullRow) {
            cnt++;
            for (int j = row; j > highestNotEmpty; j--) {
                _field[j] = _field[j - 1];
            }
            std::fill(_field[highestNotEmpty].begin() + 1, _field[highestNotEmpty].end() - 1, QPixmap());
            highestNotEmpty++;

            scene->removeItem(currentFallen);
            currentFallen = generateFallen(scene);
            scene->addItem(currentFallen);
        }
    }
    if (cnt) calculateScore(cnt);
    deleteRows += cnt;
    levelUp();
}

bool Field::doCollision() {
   bool hasFilled = false;
   for (auto &item: currentTetrimino->_blocks) {
       hasFilled |= getCell({static_cast<int>(currentTetrimino->topLeftCorner.ry() + item.first),
                             static_cast<int>(currentTetrimino->topLeftCorner.rx() + item.second)});
   }
   return hasFilled;
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
    Tetrimino *F = new Tetrimino(tetriminoesInit[nextFigure], nextFigure, this, scene);
    F->setCoordinates(START_POS);
    generateNextId();
    changeImage(nextFigure);
    return F;
}

Fallen *Field::generateFallen(QGraphicsScene *scene) {
    Fallen *F = new Fallen(this, scene);
    return F;
}

bool Field::getCell(std::pair<int, int> coords) const {
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

int Field::getScore() const {
    return score;
}

QPixmap Field::get(int x, int y) const {
    return _field[x][y];
}

std::size_t Field::getFIELD_Ht() const {
    return FIELD_Ht;
}

std::size_t Field::getFIELD_W() const {
    return FIELD_W;
}

int Field::levelUp() {
    if (deleteRows >= (curLevel + 1) * 10) {
        curLevel++;
        tetriminoesInit.emplace_back(addToTetriminoesInit());
    }
    return curLevel;
}

void Field::changeImage(int nextFigure) { 
    if (nextFigure < 7) {
        QPixmap pix(ImgSrc[nextFigure]);
        _lf->setPixmap(pix);
    }

}

std::vector<std::pair<int, int>> Field::addToTetriminoesInit() {
    size_t blocks = getRand() % possibleSize.size();
    std::vector<std::pair<int, int>> newFigure;
    while (newFigure.size() < possibleSize[blocks]) {
        int x = getRand() % NUM_OF_BLOCKS;
        int y = getRand() % NUM_OF_BLOCKS;
        newFigure.emplace_back(std::make_pair(x, y));
    }
    return newFigure;
}
