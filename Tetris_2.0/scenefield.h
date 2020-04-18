#ifndef SCENEFIELD_H
#define SCENEFIELD_H
#include "QGraphicsItem"
#include "field.h"

class SceneField : public QGraphicsItem
{
public:
    SceneField();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    Field *field;
    static const std::size_t FIELD_Ht = 20;
    static const std::size_t FIELD_W = 10;
};

#endif // SCENEFIELD_H
