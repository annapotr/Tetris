#include "field.h"
#include "figures.h"
#include <iostream>
#include <cmath>
#include <array>
#include <utility>
#include <algorithm>

using std::move;
using std::any_of;
using std::size_t;

Field::Field(int level):  gameState(true), curLevel(level), score(0), highestNotEmpty(FIELD_Ht - 1) {
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
    switch(cnt) {
        case(1): {
            score += 40 * (curLevel + 1);
            return;
        }
        case(2): {
            score += 100 * (curLevel + 1);
            return;
        }
        case(3): {
            score += 300 * (curLevel + 1);
            return;
        }
        default: {
            score += 1200 * (curLevel + 1);
            return;
        }
    }
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
            std::array<bool, FIELD_W > tmp = move(_field[i]);
            for (size_t j = i - 1; j >= highestNotEmpty; j--) {
                _field[j + 1] = move(_field[j]);
            }
            _field[highestNotEmpty] = move(tmp);
            calculateScore(cnt);
            std::cout << '\n';
        }
    }
}

bool Field::doCollision() {
   std::array<bool, 4> coords;
   coords.fill(false);
   for (size_t i = 0; i < currentTetrimino->items.size(); i++) {
       coords[i] = getCell({currentTetrimino->items[i].first + 1, currentTetrimino->items[i].second});
   }
   return any_of(coords.begin(), coords.end(), [](bool i){return i;});
}

void Field::fill() {
    while (!doCollision()) {
        currentTetrimino->falling();
    }
    currentTetrimino->isFalling = false;
    for (size_t i = 0; i  < currentTetrimino->items.size(); i++) {
        setCell(currentTetrimino->items[i]);
        if (highestNotEmpty > currentTetrimino->items[i].first) highestNotEmpty = currentTetrimino->items[i].first;
    }
}

Figures *Field::generateNext() {
    int x = (1 + rand() % 7);
    switch(x) {
        case(1): {
            Figures *I = new Figures(tetriminoesInit[x - 1], tetriminoes::I);
            I->setCoordinates(this, 3);
            return I;
        }
        case(2): {
            Figures *J = new Figures(tetriminoesInit[x - 1],tetriminoes::J);
            J->setCoordinates(this, 3);
            return J;
        }
        case(3): {
            Figures *L = new Figures(tetriminoesInit[x - 1],tetriminoes::L);
            L->setCoordinates(this, 3);
            return L;
        }
        case(4): {
            Figures *O = new Figures(tetriminoesInit[x - 1],tetriminoes::O);
            O->setCoordinates(this, 3);
            return O;
        }
        case(5): {
            Figures *S = new Figures(tetriminoesInit[x - 1],tetriminoes::S);
            S->setCoordinates(this, 3);
            return S;
        }
        case(6): {
            Figures *T = new Figures(tetriminoesInit[x - 1],tetriminoes::T);
            T->setCoordinates(this, 3);
            return T;
        }
        default: {
            Figures *Z = new Figures(tetriminoesInit[x - 1],tetriminoes::Z);
            Z->setCoordinates(this, 3);
            return Z;
        }
    }
}

bool Field::getCell(std::pair<int, int> coords){
    return _field[coords.first][coords.second];
}

bool Field::getState() {
    if (highestNotEmpty == 0) gameState = false;
    return gameState;
}

void Field::setCell(std::pair<int, int> coords){
    _field[coords.first][coords.second] = true;
}

int Field::getScore(){
    return score;
}
