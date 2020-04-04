#ifndef FIGURES_H
#define FIGURES_H
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include "fiend.h"

class Figures : public QGraphicsItem
{
public:
    Figures(int type, Field *f);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void advance(int phase) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    qreal angle;
    qreal speed;
    bool DoCollision();
    void fill();
    int type;
    //позиция фигуры на поле
    std::pair<float,float> item1;
    std::pair<float,float> item2;
    std::pair<float,float> item3;
    std::pair<float,float> item4;
    Field *f;
    bool flag = true;
};

/*
class Figures
{
public:
    Figures(int type, QGraphicsScene *scene);
private:
    void Figure_1(QGraphicsScene *scene);
    void Figure_2(QGraphicsScene *scene);
    void Figure_3(QGraphicsScene *scene);
    void Figure_4(QGraphicsScene *scene);
    void Figure_5(QGraphicsScene *scene);

};*/

#endif // FIGURES_H
