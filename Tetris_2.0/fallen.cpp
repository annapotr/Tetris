#include "fallen.h"
#include <QBrush>

Fallen::Fallen(Field *f, QGraphicsScene *scene)
{
    this->field = f;
    this->scene_ = scene;
}

QRectF Fallen::boundingRect() const {
    return QRectF(0,0,250,500);
}

void Fallen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (size_t i = 0; i < field->getFIELD_Ht(); i++) {
        for (size_t j = 0; j < field->getFIELD_W(); j++) {
            QRectF rec = QRectF(25 * j, 25 * i+10, 25, 25);
            if (!field->get(i,j).isNull()) {
                //QPixmap pix(":/red_block.png");
                QPixmap pix(field->get(i,j));
                //QBrush Brush(field->get(i,j));
                painter->fillRect(rec,pix);
                painter->drawRect(rec);
            }
        }
    }
}


