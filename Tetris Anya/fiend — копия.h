#ifndef FIEND_H
#define FIEND_H

#include <cstdio>
#include <array>
#include <vector>

class Field {
public:
    explicit Field();
    bool getCell(int x, int y);
    void setCell(int x,int y);


private:
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;
    bool GameState = true;

    void checkRow();

    std::size_t HighestNotEmpty = FIELD_Ht - 1; //the lowest
    std::array<std::array<bool, FIELD_W>, FIELD_Ht> _field;
};

//мб хранить верхнюю (наивысшую) хоть как-то занятую строку(?)

#endif // FIEND_H
