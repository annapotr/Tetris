#include "fallen.h"
#include <QBrush>
#include <QPixmap>

Fallen::Fallen(Field *f, QGraphicsScene *scene) {
    this->field = f;
    this->scene_ = scene;
}

QRectF Fallen::boundingRect() const {
    return QRectF(0, 0, 280, 534);
}

void Fallen::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    for (size_t i = 0; i <= 20; i++) {
        for (size_t j = 0; j <= 10; j++) {
            QRectF rec = QRectF(BLOCK_PX * j, BLOCK_PX * i + 10, BLOCK_PX, BLOCK_PX);
            if (!field->get(i,j).isNull()) {
                QPixmap pix(field->get(i,j));
                painter->fillRect(rec,pix);
                painter->drawRect(rec);
            }
        }
    }

}
