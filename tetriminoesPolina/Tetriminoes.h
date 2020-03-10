#ifndef TETRIMINOES_H
#define TETRIMINOES_H

#include <cstdio>
#include <array>
#include <vector>

const std::size_t NUM_OF_BLOCKS = 4;

enum class tetriminoes {
    I,
    J,
    L,
    O,
    S,
    T,
    Z
};

enum class tetriminoes_color {
    BLUE,
    DARK_BLUE,
    ORANGE,
    YELLOW,
    GREEN,
    PURPLE,
    RED
};

tetriminoes_color make_color(tetriminoes t);

class BasePiece {
public:
    explicit BasePiece(std::array<int, NUM_OF_BLOCKS> blocks);
    void printBlockTmp() const;
private:
    static const std::size_t BLOCK_H = 4;
    static const std::size_t BLOCK_W = 2;

    size_t _nBlocks;
    std::array<std::array<bool, BLOCK_W>, BLOCK_H> _blocks;
};

class Tetrimino : public BasePiece {
public:
    Tetrimino(std::array<int, NUM_OF_BLOCKS> blocks, tetriminoes type);
private:
    tetriminoes_color _color;
    tetriminoes _type;
};

#endif // TETRIMINOES_H
