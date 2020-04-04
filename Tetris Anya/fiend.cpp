#include "fiend.h"
#include <iostream>
#include <cstdio>
#include <array>
#include <utility>
#include <vector>
#include <QDebug>

using std::move;

Field::Field() {
    for (std::size_t i = 0; i < FIELD_Ht; i++) {//20
        for (std::size_t j = 0; j < FIELD_W; j++) {//10
            _field[i][j] = false;
        }
    }
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
        }
    }
    return;
}


bool Field::getCell(int x, int y){
    return _field[x][y];
}

void Field::setCell(int x, int y){
    _field[x][y] = true;
}

