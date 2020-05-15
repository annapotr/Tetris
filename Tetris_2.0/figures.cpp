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
#include <iostream>
#include <algorithm>
#include "gameover.h"

using std::vector;
using std::size_t;
using std::pair;

int BLOCK_PX = 25;
int PADDING = 5;

vector<vector<pair<int, int>>> tetriminoesInit = {
    {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}}
    }
};

QPixmap make_pix(tetriminoes t) {
    switch(t) {
        case(tetriminoes::I):{
            QPixmap pix(":/reddd.png");
            return pix;
        }
        case(tetriminoes::J):{
            QPixmap pix(":/orange.png");
            return pix;
        }
        case(tetriminoes::L):{
            QPixmap pix(":/yellow_block.png");
            return pix;
        }
        case(tetriminoes::O):{
            QPixmap pix(":/green_block.png");
            return pix;
        }
        case(tetriminoes::S): {
            QPixmap pix(":/blue_blue_block.png");
            return pix;
        }
        case(tetriminoes::T): {
            QPixmap pix(":/blue_block.png");
            return pix;
        }
        case(tetriminoes::Z): {
            QPixmap pix(":/pink_block.png");
            return pix;
        }
    }
}

Tetrimino::Tetrimino(std::vector<pair<int, int>> blocks, tetriminoes type, Field *f, QGraphicsScene *scene)
    : type_(type), pix_(make_pix(type_)), field(f), scene_(scene),
      speed(2), paused_speed(2) {
    for (auto &k: blocks) {
        _blocks.push_back(k);
        if (max_row < k.first) max_row = k.first;
        if (max_col < k.second) max_col = k.second;
    }

    /*qDebug() << "L\n";

    for (std::size_t i = 0; i < _blocks.size(); i++) {
        qDebug() << _blocks[i].first << ' ' << _blocks[i].second;
    }

    qDebug() << "Max y & x: " << max_row << ' ' << max_col << '\n';*/
}

void Tetrimino::updateTetrimino(vector<pair<int, int>> blocks, tetriminoes type, Field *f, QGraphicsScene *scene) {
    type_ = type, pix_ = make_pix(type_), field = f, scene_ = scene , speed = 5, paused_speed = 5;
    for (auto &k: blocks) {
        _blocks.push_back(k);
        if (max_row < k.first) max_row = k.first;
        if (max_col < k.second) max_col = k.second;
    }
}

void Tetrimino::setCoordinates(int start) {
    topLeftCorner.rx() += start;
    setPos(topLeftCorner.rx() * BLOCK_PX, PADDING * 1.5);
    boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));
}

QRectF Tetrimino::boundingRect() const {
    return boundingRectangale;
}

void Tetrimino::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pix(pix_);
    for (auto &item: _blocks) {
        QRectF rec = QRectF(BLOCK_PX * item.second,
                            BLOCK_PX * item.first, BLOCK_PX, BLOCK_PX);
        painter->fillRect(rec,pix);
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

void Tetrimino::left() {
    if (topLeftCorner.rx() > 1){
        topLeftCorner.rx()--;
        setPos(mapToScene(-BLOCK_PX, 0));
    }
    return;
}

void Tetrimino::right() {
    if (topLeftCorner.rx() + max_col < field->getFIELD_W()){
        topLeftCorner.rx()++;
        setPos(mapToScene(BLOCK_PX, 0));
    }
    return;
}

void Tetrimino::fastLanding() {
    while (!field->doCollision()
           && (topLeftCorner.ry() + (max_row + 1) < field->getFIELD_Ht() + 1)) {
        topLeftCorner.ry()++;
        //setPos(mapToScene(topLeftCorner.rx() * BLOCK_PX, topLeftCorner.ry() * BLOCK_PX));
        setPos(topLeftCorner.rx() * BLOCK_PX, topLeftCorner.ry() * BLOCK_PX);
    }
}

void Tetrimino::advance(int phase) {
    if(!phase) return;
    //qDebug() << "X of tLC: " << topLeftCorner.rx() << "Y of tLC: " << topLeftCorner.ry();

    if (field->getState() == gameStates::PAUSED) {
        if(speed != 0) paused_speed = speed;
        speed = 0;
        return;
    }

    if (field->getState() == gameStates::INPROCESS) {
        speed = paused_speed;
    }

    if (field->doCollision()) {
       field->fill(pix_);
       speed = 0;
       scene_->removeItem(this);
       field->printFieldTmp();
       if (field->getState() == gameStates::GAMEOVER) {
           field->changeBlackImg();
           hide();
           GameOver gameover(field,scene_);
           gameover.setModal(true);
           gameover.exec();
           return;
       }
       field->currentTetrimino = field->generateNext(scene_);
       scene_->addItem(field->currentTetrimino);
    }
    setPos(mapToParent(0,speed));
    topLeftCorner.ry() += speed/25;
}

void Tetrimino::turn90back() {
    //забанить повороты после коллизии
    std::vector<std::pair<int, int>> prevs;
    if(field->getState() == gameStates::INPROCESS) {
        prevs = _blocks;
        for (std::size_t i = 0; i < _blocks.size(); i++) {
            _blocks[i] = {max_col - _blocks[i].second, _blocks[i].first};
        }

        if (field->banRotate()) {
            swap(_blocks, prevs);
            return;
        }

        max_row = maxParam(0);
        max_col = maxParam(1);

        boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));
    }
}

void Tetrimino::turn90up() {
    //забанить повороты после коллизии
    std::vector<std::pair<int, int>> prevs;
    if(field->getState() == gameStates::INPROCESS) {
        prevs = _blocks;
        for (std::size_t i = 0; i < _blocks.size(); i++) {
            _blocks[i] = {_blocks[i].second, max_row - _blocks[i].first};
        }

        if (field->banRotate()) {
            swap(_blocks, prevs);
            return;
        }

        max_row = maxParam(0);
        max_col = maxParam(1);

        boundingRectangale.setRect(0, 0, BLOCK_PX * (max_col + 1), BLOCK_PX * (max_row + 1));
    }
}
