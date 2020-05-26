#include "Tetriminoes.h"
#include <array>
#include <iostream>

using std::array;

tetriminoes_color make_color(tetriminoes t) {
    switch(t) {
        case(tetriminoes::I): return tetriminoes_color::BLUE;
        case(tetriminoes::J): return tetriminoes_color::DARK_BLUE;
        case(tetriminoes::L): return tetriminoes_color::ORANGE;
        case(tetriminoes::O): return tetriminoes_color::YELLOW;
        case(tetriminoes::S): return tetriminoes_color::GREEN;
        case(tetriminoes::T): return tetriminoes_color::PURPLE;
        case(tetriminoes::Z): return tetriminoes_color::RED;
    }
}

BasePiece::BasePiece(array<int, NUM_OF_BLOCKS> blocks): _nBlocks(blocks.size()) {
    for (auto &row: _blocks) {
        row.fill(false);
    }
    for (auto &k: blocks) {
        _blocks[k / BLOCK_W][k % BLOCK_W] = true;
    }
}

void BasePiece::printBlockTmp() const {
    for (std::size_t i = 0; i < BLOCK_H; i++) {
        for (std::size_t j = 0; j < BLOCK_W; j++) {
            std::cout << _blocks[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

Tetrimino::Tetrimino(std::array<int, NUM_OF_BLOCKS> blocks, tetriminoes type): BasePiece(blocks), _color(make_color(type)), _type(type) {}
