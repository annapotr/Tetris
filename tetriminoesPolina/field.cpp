#include <iostream>
#include <cstdio>
#include <array>
#include <utility>
#include <vector>
#include "Field.h"

using std::move;

Field::Field() {
    for (std::size_t i = 0; i < FIELD_Ht; i++) {
        for (std::size_t j = 0; j < FIELD_W; j++) {
            _field[i][j] = false;
        }
    }
}

void Field::RunGame() {
    if (HighestNotEmpty == FIELD_Ht - 1) {
        GameState = false;
        return;
    }
    else {
        printFieldTmp();
        for  (int i = 0; i < 7; i++) { //tmp!
            Tetrimino A = generateNext();
            A.printBlockTmp();
            std::cout << '\n';
        }
        checkRow();
    }
}

Tetrimino Field::generateNext() {
    int x = (rand() % 7 + 1);
    switch(x) {
        case(1): {
        Tetrimino I({0, 2, 4, 6}, tetriminoes::I);
        return I;
        }
        case(2): {
        Tetrimino J({3, 5, 6, 7}, tetriminoes::J);
        return J;
        }
        case(3): {
         Tetrimino L({2, 4, 6, 7}, tetriminoes::L);
         return L;
        }
        case(4): {
         Tetrimino O({4, 5, 6, 7}, tetriminoes::O);
         return O;
        }
        case(5): {
        Tetrimino S({2, 4, 5, 7}, tetriminoes::S);
        return S;
        }
        case(6): {
        Tetrimino T({3, 4, 5, 7}, tetriminoes::T);
        return T;
        }
        case(7): {
        Tetrimino Z({3, 4, 5, 6}, tetriminoes::Z);
        return Z;
        }
    }
}

void Field::printFieldTmp() const {
    for (std::size_t i = 0; i < FIELD_Ht; i++) {
        for (std::size_t j = 0; j < FIELD_W; j++) {
            std::cout << _field[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Field::setRowTmp(std::size_t coordRow) {
   _field[coordRow].fill(true);
}

void Field::setHalfRowTmp(std::size_t coordRow) {
   for (std::size_t j = 0; j < FIELD_W/2; j++) {
       _field[coordRow][j] = true;
   }
   HighestNotEmpty = coordRow; //tmp string
}

void Field::checkRow() { //сколько строк проверять? наверное, от самого нижнего до самого верхнего хоть как-то заполненного ряда.
    int cnt = 0; //for scoring, TODO
    for (std::size_t i = HighestNotEmpty; i < FIELD_Ht; i++) {
        bool row = true;
        for (auto &cell: _field[i]) {
            row &= cell;
        }
        if (row) {
            cnt++; //for scoring, TODO
            _field[i].fill(false);
            std::array<bool, FIELD_W > tmp = move(_field[i]);
            for (std::size_t j = i - 1; j >= HighestNotEmpty; j--) {
                _field[j + 1] = move(_field[j]);
            }
            _field[HighestNotEmpty] = move(tmp);
            std::cout << '\n';
            //printFieldTmp();
        }
    }
    return;
}

