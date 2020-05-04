#include "fallen.h"
#include <QBrush>

Fallen::Fallen(Field *f, QGraphicsScene *scene) {
    this->field = f;
    this->scene_ = scene;
}

QRectF Fallen::boundingRect() const {
    return QRectF(BLOCK_PX, BLOCK_PX, BLOCK_PX * field->getFIELD_Ht(), BLOCK_PX * field->getFIELD_W());
}

void Fallen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (size_t i = 0; i <= field->getFIELD_Ht(); i++) {
        for (size_t j = 0; j <= field->getFIELD_W(); j++) {
            QRectF rec = QRectF(BLOCK_PX * j, BLOCK_PX * i + 10, BLOCK_PX, BLOCK_PX);
            if (!field->get(i, j).isNull()) {
                //QPixmap pix(":/red_block.png");
                QPixmap pix(field->get(i, j));
                //QBrush Brush(field->get(i,j));
                painter->fillRect(rec, pix);
                painter->drawRect(rec);
            }
        }
    }
}


