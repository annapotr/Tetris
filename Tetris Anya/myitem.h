#ifndef MYITEM_H
#define MYITEM_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class MyItem : public QGraphicsItem
{
public:
    MyItem(int StartX, int StartY);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void advance(int phase) override;
private:
    qreal angle;
    qreal speed;
    void DoCollision();
};

#endif // MYITEM_H
