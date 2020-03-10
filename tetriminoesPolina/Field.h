#ifndef FIELD_H
#define FIELD_H

#include <cstdio>
#include <array>
#include <vector>
#include "Tetriminoes.h"

class Field {
public:
    explicit Field();
    void RunGame(); //TODO
    Tetrimino generateNext();

//these functions excist only for testing other functions:D
    void printFieldTmp() const; //
    void setRowTmp(std::size_t coordRow); //
    void setHalfRowTmp(std::size_t coordRow); //
// end of tese functions

private:
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;
    bool GameState = true;

    void checkRow();
//    void newState();

    std::size_t HighestNotEmpty = FIELD_Ht - 1; //the lowest
    std::array<std::array<bool, FIELD_W>, FIELD_Ht> _field;
};

//мб хранить верхнюю (наивысшую) хоть как-то занятую строку(?)

#endif // FIELD_H
