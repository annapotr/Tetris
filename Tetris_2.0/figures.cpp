#include "figures.h"
#include "field.h"
#include "game.h"
#include <QColor>
#include <QDebug>
#include <QKeyEvent>
#include <array>
#include <iostream>

using std::vector;
using std::size_t;

vector<vector<int>> tetriminoesInit = {
    {
        {0, 1, 2, 3},
        {0, 4, 5, 6},
        {2, 4, 5, 6},
        {0, 1, 4, 5},
        {1, 2, 4, 5},
        {0, 1, 2, 5},
        {0, 1, 5, 6}
    }
};

QColor make_color(tetriminoes t) {
    switch(t) {
        case(tetriminoes::I): return Qt::cyan;
        case(tetriminoes::J): return Qt::blue;
        case(tetriminoes::L): {
            QColor orange(255,165,0);
            return orange;
        }
        case(tetriminoes::O): return Qt::yellow;
        case(tetriminoes::S): return Qt::red;
        case(tetriminoes::T): return Qt::darkMagenta;
        default: return Qt::green;
    }
}

Tetrimino::Tetrimino(std::vector<int> blocks, tetriminoes type, Field *f, QGraphicsScene *scene)
    : type_(type), color_(make_color(type_)), field(f), scene_(scene),
      speed(5) {
    for (auto &k: blocks) {
        _blocks.push_back({k / BLOCK_W, k % BLOCK_W});
        if (max_y < k / BLOCK_W) max_y = k / BLOCK_W;
        if (max_x < k % BLOCK_W) max_x = k % BLOCK_W;
    }
}

void Tetrimino::setCoordinates(int start) {
    topLeftCorner.rx() += start;
    topLeftCorner.ry() += PADDING/BLOCK_PX;
    setPos(topLeftCorner.rx() * BLOCK_PX, PADDING * 1.5);
    boundingRectangale.setRect(0, 0, BLOCK_PX * (max_x + 1), BLOCK_PX * (max_y + 1));
}

QRectF Tetrimino::boundingRect() const {
    return boundingRectangale;
}

void Tetrimino::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QBrush Brush(color_);
    for (auto &item: _blocks) {
        QRectF rec = QRectF(BLOCK_PX * item.second,
                            BLOCK_PX * item.first, BLOCK_PX, BLOCK_PX);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
    }
}

int Tetrimino::maxParm(bool parm) {
    int maxCol = 0, maxRow = 0;

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        maxCol = std::max(maxCol, _blocks[i].first);
        maxRow = std::max(maxRow, _blocks[i].second);
    }
    return parm ? (maxRow + 1) : (maxCol + 1);
}

void Tetrimino::left() {
    topLeftCorner.rx()--;
}
void Tetrimino::right() {
    topLeftCorner.rx()++;
}

void Tetrimino::advance(int phase) {
    if(!phase) return;
    setPos(mapToParent(0,speed));
    topLeftCorner.ry() += speed/25;

    if (field->doCollision()) {
       field->fill(color_);
       speed = 0;
       scene_->removeItem(this);
       //field->generateNext(scene_);

       field->printFieldTmp();
    }
}

void Tetrimino::turn90back() {
    int W = maxParm(1);

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        _blocks[i] = {W - _blocks[i].second - 1, _blocks[i].first};
    }
}

void Tetrimino::turn90up() {
    int H = maxParm(0);

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        _blocks[i] = {_blocks[i].second, H - _blocks[i].first - 1};
    }
}
