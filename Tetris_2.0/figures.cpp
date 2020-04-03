#include "figures.h"
#include "field.h"
#include "game.h"
#include <QColor>
#include <QDebug>
#include <QKeyEvent>
#include <array>
#include <iostream>

using std::array;
using std::size_t;

array<array<int, 4>, 7> tetriminoesInit = {
    {
        {0, 1, 2, 3},
        {1, 5, 6, 7},
        {3, 5, 6, 7},
        {1, 2, 5, 6},
        {2, 3, 5, 6},
        {1, 2, 3, 6},
        {1, 2, 6, 7}
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

Figures::Figures(std::array<int, NUM_OF_BLOCKS> blocks, tetriminoes type): type_(type), color_(make_color(type_)), speed(5) {
    //int st = 3;
    for (auto &row: _blocks) {
        row.fill(false);
    }
    for (auto &k: blocks) {
        _blocks[k / BLOCK_W][k % BLOCK_W] = true;
    }

    //setPos(mapToParent(5 + st * 25, 5));
}

void Figures::setCoordinates(Field *f, int start) {
    size_t item = 0;
    for (size_t i = 0; i < BLOCK_H; i++) {
        for (size_t j = start; j <= start + BLOCK_W; j++) {
            if (f->getCell({i, j}) || _blocks[i][j - start]) {
                items[item] = {i, j};
                item++;
            }
        }
    }
}

QRectF Figures::boundingRect() const
{
    return QRectF(0,0,100,50);
}

void Figures::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!isFalling) {
       speed = 0;
       setPos(mapToParent(0,-20));

            //Figures *figure = new Figures(type_,f);
            //scene()->addItem(figure);
    }
        QRectF rec = QRectF(0,0,25,25);
        QBrush Brush(color_);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
        QRectF rec1 = QRectF(25,25,25,25);
        QBrush Brush1(color_);
        painter->fillRect(rec1,Brush1);
        painter->drawRect(rec1);
        QRectF rec2 = QRectF(25,0,25,25);
        QBrush Brush2(color_);
        painter->fillRect(rec2,Brush2);
        painter->drawRect(rec2);
        QRectF rec3 = QRectF(50,25,25,25);
        QBrush Brush3(color_);
        painter->fillRect(rec3,Brush3);
        painter->drawRect(rec3);


    }
//    else if((int)type_ == 6){
//        if(DoCollision() && flag) {
//            speed = 0;
//            setPos(mapToParent(0,-20));
//            fill();
//            flag = false;
//            Figures *figure = new Figures(type_,f);
//            scene()->addItem(figure);
//        }
//        QRectF rec = QRectF(0,0,25,25);
//        QBrush Brush(color_);
//        painter->fillRect(rec,Brush);
//        painter->drawRect(rec);
//        QRectF rec1 = QRectF(25,25,25,25);
//        QBrush Brush1(color_);
//        painter->fillRect(rec1,Brush1);
//        painter->drawRect(rec1);
//        QRectF rec2 = QRectF(25,0,25,25);
//        QBrush Brush2(color_);
//        painter->fillRect(rec2,Brush2);
//        painter->drawRect(rec2);
//        QRectF rec3 = QRectF(50,0,25,25);
//        QBrush Brush3(color_);
//        painter->fillRect(rec3,Brush3);
//        painter->drawRect(rec3);
//    }

void Figures::falling() {
    for (size_t i = 0; i < items.size(); i++) {
        items[i].first++;
    }
}

void Figures::advance(int phase) {
    if(!phase) return;
    setPos(mapToParent(0,speed));
    for (size_t i = 0; i < items.size(); i++) {
        items[i].first += speed/25;
    }
}

void Figures::keyPressEvent(QKeyEvent *event) {

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




