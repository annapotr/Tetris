#include "figures.h"
#include "fiend.h"
#include "game.h"
#include <QDebug>
#include <QKeyEvent>


Figures::Figures(int type, Field *f)
{
    speed = 5;
    this->type = type;
    if(type == 1){
        setPos(mapToParent(80,5));
        item1 = {0,3};
        item2 = {0,4};
        item3 = {1,4};
        item4 = {1,5};
    }
    if(type == 2){
        setPos(mapToParent(105,5));
        item1 = {0,4};
        item2 = {0,5};
        item3 = {0,6};
        item4 = {1,5};
    }
    this->f = f;
}


QRectF Figures::boundingRect() const
{
    return QRectF(0,0,100,50);
}

void Figures::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(type == 1){
        if(DoCollision() && flag) {
            speed = 0;
            setPos(mapToParent(0,-20));
            fill();
            flag = false;
            Figures *figure = new Figures(2,f);
            scene()->addItem(figure);
        }
        QRectF rec = QRectF(0,0,25,25);
        QBrush Brush(Qt::green);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
        QRectF rec1 = QRectF(25,25,25,25);
        QBrush Brush1(Qt::green);
        painter->fillRect(rec1,Brush1);
        painter->drawRect(rec1);
        QRectF rec2 = QRectF(25,0,25,25);
        QBrush Brush2(Qt::green);
        painter->fillRect(rec2,Brush2);
        painter->drawRect(rec2);
        QRectF rec3 = QRectF(50,25,25,25);
        QBrush Brush3(Qt::green);
        painter->fillRect(rec3,Brush3);
        painter->drawRect(rec3);


    }else if(type == 2){
        if(DoCollision() && flag) {
            speed = 0;
            setPos(mapToParent(0,-20));
            fill();
            flag = false;
            Figures *figure = new Figures(2,f);
            scene()->addItem(figure);
        }
        QRectF rec = QRectF(0,0,25,25);
        QBrush Brush(Qt::blue);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
        QRectF rec1 = QRectF(25,25,25,25);
        QBrush Brush1(Qt::blue);
        painter->fillRect(rec1,Brush1);
        painter->drawRect(rec1);
        QRectF rec2 = QRectF(25,0,25,25);
        QBrush Brush2(Qt::blue);
        painter->fillRect(rec2,Brush2);
        painter->drawRect(rec2);
        QRectF rec3 = QRectF(50,0,25,25);
        QBrush Brush3(Qt::blue);
        painter->fillRect(rec3,Brush3);
        painter->drawRect(rec3);
    }

}

void Figures::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,speed));
    item1.first += speed/25;
    item2.first += speed/25;
    item3.first += speed/25;
    item4.first += speed/25;

}

bool Figures::DoCollision()
{
    if(type == 1){
        QPointF a = sceneTransform().map(QPointF(80, 5));
        //qDebug() << a.ry();
        int b = a.ry();
        qDebug() << b << ' ' << b/25 << ' ' << (b-1)/25 << ' ' << b/25-1 << ' ' << (b-1)/25-1 ;
        if((f->getCell((int)item1.first+1,(int)item1.second) || (f->getCell((int)item2.first+1,(int)item2.second))
                || (f->getCell((b-1)/25-1,(int)item3.second)) || (f->getCell((int)item4.first+1,(int)item4.second))
                || ((b)/25-1 >= 20) || ((b)/25-1 >= 20)
                || ((b)/25 >= 20) || ((b)/25 >= 20))) {
            //qDebug() << a.rx() << ' ' << a.ry() << ' ' <<  b << ' ' << c;
            return true;
        }
        return false;
    }else if(type == 2){
        QPointF a = sceneTransform().map(QPointF(105, 5));
        //qDebug() << a.ry();
        int b = a.rx();
        //qDebug() << b/25;
        if((f->getCell((int)item1.first+1,(int)item1.second) || (f->getCell((int)item2.first+1,(int)item2.second))
                || (f->getCell((b-1)/25-1,(int)item3.second)) || (f->getCell((int)item4.first+1,(int)item4.second))
                || ((int)item1.first >= 20) || ((int)item2.first >= 20)
                || ((b-1)/25-1 >= 20) || ((b-1)/25-1 >= 20))) {
            //qDebug() << a.rx() << ' ' << a.ry() << ' ' <<  b << ' ' << c;
            return true;
        }
        return false;
    }
}

void Figures::fill(){
    if(type == 1){
        QPointF a = sceneTransform().map(QPointF(80, 5));
        int b = a.ry()/25;
        f->setCell((int)item1.first,(int)item1.second);
        f->setCell((int)item2.first,(int)item2.second);
        f->setCell(b,(int)item3.second);
        f->setCell(b,(int)item4.second);
    }else if(type == 2){
        f->setCell((int)item1.first,(int)item1.second);
        f->setCell((int)item2.first,(int)item2.second);
        f->setCell((int)item3.first,(int)item3.second);
        f->setCell((int)item4.first,(int)item4.second);
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




