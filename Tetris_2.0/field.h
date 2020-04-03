#ifndef FIEND_H
#define FIEND_H

#include "figures.h"
#include <QObject>
#include <iosfwd>
#include <array>
#include <utility>

class Figures;

class Field {
public:
    explicit Field(int level);

    bool getCell(std::pair<int, int> coords);
    void setCell(std::pair<int, int> coords);
    int getScore();
    bool getState();

    void printFieldTmp() const;

    void checkRow();
    void calculateScore(int cnt);
    void fill();
    bool doCollision();
    Figures *generateNext();

    Figures *currentTetrimino;

private:
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;

    bool gameState;
    int curLevel, score;
    std::size_t highestNotEmpty;
    std::array<std::array<bool, FIELD_W>, FIELD_Ht + 1> _field;
};

#endif // FIEND_H
