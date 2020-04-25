#include "figures.h"
#include "field.h"
#include "fallen.h"
#include "game.h"
#include <QColor>
#include <QDebug>
#include <QKeyEvent>
#include <array>
#include <iostream>
#include <QPainter>

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
        if (max_row < k / BLOCK_W) max_row = k / BLOCK_W;
        if (max_col < k % BLOCK_W) max_col = k % BLOCK_W;
    }

    /*qDebug() << "L\n";

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        qDebug() << _blocks[i].first << ' ' << _blocks[i].second;
    }

    qDebug() << "Max y & x: " << max_row << ' ' << max_col << '\n';*/
}

void Tetrimino::setCoordinates(int start) {
    topLeftCorner.rx() += start;
    topLeftCorner.ry() += PADDING/BLOCK_PX;
    setPos(topLeftCorner.rx() * BLOCK_PX, PADDING * 1.5);
    boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));

    //qDebug() << "top Left Corner's X: " << topLeftCorner.rx() << " Y: " << topLeftCorner.ry() << '\n';
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

int Tetrimino::maxParam(bool param) {
    int maxP = 0;

    for (std::size_t i = 0; i < this->_blocks.size(); i++) {
        if (!param) {
            maxP = std::max(maxP, _blocks[i].first);//Rows
        } else {
            maxP = std::max(maxP, _blocks[i].second);//Cols
        }
    }

    return maxP;
}

int Tetrimino::minParam(bool param) {
    int minP = 5;

    for (std::size_t i = 0; i < this->_blocks.size(); i++) {
        if (!param) {
            minP = std::max(minP, _blocks[i].first);//Rows
        } else {
            minP = std::max(minP, _blocks[i].second);//Cols
        }
    }

    return minP;
}

void Tetrimino::left() {
    topLeftCorner.rx()--;
}
void Tetrimino::right() {
    topLeftCorner.rx()++;
}

void Tetrimino::advance(int phase) {
    if(!phase) return;
    qDebug() << "X of tLC: " << topLeftCorner.rx() << "Y of tLC: " << topLeftCorner.ry();

    if (field->doCollision()) {
       field->fill(color_);
       speed = 0;
       scene_->removeItem(this);
       //field->printFieldTmp();
       if (field->getState() == gameStates::GAMEOVER) return;
       field->currentTetrimino = field->generateNext(scene_);
       scene_->addItem(field->currentTetrimino);

    }

    setPos(mapToParent(0,speed));
    topLeftCorner.ry() += speed/25;
}

void Tetrimino::turn90back() {

    //qDebug() << "max_y of 'L' is " << max_y << '\n';
    //qDebug() << "max_x of 'L' is " << max_x << '\n';

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        _blocks[i] = {max_col - _blocks[i].second, _blocks[i].first};
    }

    max_row = maxParam(0);
    max_col = maxParam(1);

    /*topLeftCorner.ry() = ;
    topLeftCorner.rx() = ;*/

    /*if (!isVertical) { // Wait for some seconds before turn!
        isVertical = 1;
        topLeftCorner.ry() -= (1 + speed/25);
        //topLeftCorner.rx() += 1;
    } else {
        isVertical = 0;
        topLeftCorner.ry() += (1 + speed/25);
        //topLeftCorner.rx() -= 1;
    }*/

    setPos(mapToParent(0, speed));
    boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));
}

void Tetrimino::turn90up() {

    //qDebug() << "max_y of 'L' is " << max_row << '\n';
    //qDebug() << "max_x of 'L' is " << max_col << '\n';

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        _blocks[i] = {_blocks[i].second, max_row - _blocks[i].first};
    }

    max_row = maxParam(0);
    max_col = maxParam(1);

    setPos(mapToParent(0, speed));
    boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));
}
