#include "scenefield.h"
#include "iostream"

SceneField::SceneField()
{

}

QRectF SceneField::boundingRect() const {
    return QRectF(20,10,265,525);
}

void SceneField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (size_t i = 0; i < FIELD_Ht; i++) {
        for (size_t j = 0; j < FIELD_W; j++) {
            //std::cout << field[i][j].isValid() << ' ';
            //QBrush Brush(field[i][j]);
        }
    }
    /*
    QBrush Brush(color_);
    for (auto &item: _blocks) {
        QRectF rec = QRectF(BLOCK_PX * item.second,
                            BLOCK_PX * item.first, BLOCK_PX, BLOCK_PX);
        painter->fillRect(rec,Brush);
        painter->drawRect(rec);
    }*/
}
