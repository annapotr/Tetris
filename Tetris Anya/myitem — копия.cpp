#include "myitem.h"
#include "figures.h"


MyItem::MyItem(int StartX, int StartY)
{
    speed = 10;
    setPos(mapToParent(StartX,StartY));

}

QRectF MyItem::boundingRect() const
{
    return QRectF(0,0,25,25);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::green);
    if(!(scene()->collidingItems(this).isEmpty())) {
        DoCollision();
    }
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

void MyItem::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,speed));
}

void MyItem::DoCollision()
{
    speed = 0;
    setPos(mapToParent(0,-10));
}
