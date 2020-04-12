#include "field.h"
#include "figures.h"
#include <iostream>
#include <array>
#include <utility>

using std::move;
using std::size_t;

std::vector<int> points = {40, 100, 300, 1200};

Field::Field(int level)
    : gameState(gameStates::INPROCESS), curLevel(level), score(0), highestNotEmpty(FIELD_Ht - 1) {
    for (size_t i = 0; i < FIELD_Ht; i++) {
        _field[i].fill(false);
    }
    _field[FIELD_Ht].fill(true);
}

void Field::printFieldTmp() const {
    for (size_t i = 0; i < FIELD_Ht; i++) {
        for (size_t j = 0; j < FIELD_W; j++) {
            std::cout << _field[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Field::calculateScore(int cnt) {
    if (cnt > 4) cnt = 4;
    score += points[cnt - 1] * (curLevel + 1);
}

void Field::checkRow() {
    int cnt = 0;
    for (size_t i = highestNotEmpty; i < FIELD_Ht; i++) {
        bool row = true;
        for (auto &cell: _field[i]) {
            row &= cell;
        }
        if (row) {
            cnt++;
            _field[i].fill(false);
            for (int j = i - 1; j >= highestNotEmpty; j--) {
                _field[j + 1] = move(_field[j]);
            }
            _field[highestNotEmpty].fill(false);
            highestNotEmpty++;
            calculateScore(cnt);
        }
    }
}

bool Field::doCollision() {
   bool hasFilled = false;
   for (auto &item: currentTetrimino->_blocks) {
       hasFilled |= getCell({currentTetrimino->highLeftCorner.ry() + item.first + 1, // строка
                             currentTetrimino->highLeftCorner.rx() + item.second}); // столбец
   }
   return hasFilled;
}

void Field::fill() {
    for (auto &item: currentTetrimino->_blocks) {
        int x = currentTetrimino->highLeftCorner.ry() + item.first;
        int y = START_POS + item.second;
        setCell({x, y});
        if (highestNotEmpty > x) highestNotEmpty = x;
    }
}

Tetrimino *Field::generateNext() {
    int x = (rand() % 7);
    Tetrimino *F = new Tetrimino(tetriminoesInit[x], static_cast<tetriminoes>(x), this);
    F->setCoordinates(START_POS); //перенести куда-нибудь!
    return F;
}

bool Field::getCell(std::pair<int, int> coords) {
    return _field[coords.first][coords.second];
}

gameStates Field::getState() {
    if (highestNotEmpty == 0) gameState = gameStates::GAMEOVER;
    // PAUSED;
    return gameState;
}

void Field::setCell(std::pair<int, int> coords) {
    _field[coords.first][coords.second] = true;
}

int Field::getScore() {
    return score;
}
