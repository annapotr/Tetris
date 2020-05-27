#ifndef FALLEN_H
#define FALLEN_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QPointF>
#include "field.h"

class Field;

class Fallen  : public QGraphicsItem {
public:
    Fallen(Field *f, QGraphicsScene *scene);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    Field *field;
    QGraphicsScene *scene_;

};

#endif // FALLEN_H
