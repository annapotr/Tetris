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

Tetrimino::Tetrimino(std::vector<int> blocks, tetriminoes type, Field *f)
    : type_(type), color_(make_color(type_)), field(f), speed(5) {
    for (auto &k: blocks) {
        _blocks.push_back({k / BLOCK_W, k % BLOCK_W});
    }
}

void Tetrimino::setCoordinates(int start) {
    highLeftCorner.rx() += start;
    highLeftCorner.ry() += PADDING/BLOCK_PX;
}

QRectF Tetrimino::boundingRect() const {
    return QRectF(0, 0, 100, 50);
}

void Tetrimino::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QBrush Brush(color_);
    for (auto &item: _blocks) {
        QRectF rec = QRectF(3.0 * BLOCK_PX + BLOCK_PX * item.second, \
                            1.5 * PADDING + BLOCK_PX * item.first, BLOCK_PX, BLOCK_PX);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
    }
}

void Tetrimino::advance(int phase) {
    if(!phase) return;
    setPos(mapToParent(0,speed));
    highLeftCorner.ry() += speed/25;

    int cnt = 0;
    if (field->doCollision()) {
       field->fill();
       speed = 0;
       cnt++;
       field->printFieldTmp();
       std::cout << "cnt: " << cnt << '\n';
       return;
    }
}

void Tetrimino::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Up) {
        //calling the function of turning to 90 degrees onward
        //
        qDebug() << "Turn 90 onward!";
    }

    if (event->key() == Qt::Key_Down) {
        //calling the function of turning to 90 degrees backward
        //
        qDebug() << "Turn 90 backward!";
    }

    if (event->key() == Qt::Key_Left) {
        //calling the function of left moving
        //
        qDebug() << "Left!";
    }

    if (event->key() == Qt::Key_Right) {
        //calling the function of right moving
        //
        qDebug() << "Right!";
    }

    if (event->key() == Qt::Key_Space) {
        qDebug() << "Fast landing!";
    }
}




