#ifndef FIGURES_H
#define FIGURES_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QPointF>
#include <QPixmap>
#include <utility>
#include <vector>
#include "field.h"

class Field;

extern int BLOCK_PX;
extern int PADDING;
extern std::vector<std::vector<std::pair<int, int>>> tetriminoesInit;
constexpr std::size_t NUM_OF_BLOCKS = 4;

class Tetrimino : public QGraphicsItem {
public:
    Tetrimino(std::vector<std::pair<int, int>> blocks, int t, Field *f, QGraphicsScene *scene);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void setCoordinates(int start);
    void left();
    void right();
    void fastLanding();

    std::vector<std::pair<int, int>> _blocks;
    QPointF topLeftCorner;

    int maxParam(bool param);
    void turn90back();
    void turn90up();


protected:
    void advance(int phase) override;

private:
    static const std::size_t BLOCK_H = 2;
    static const std::size_t BLOCK_W = 4;

    QPixmap pix_;
    Field *field;
    QGraphicsScene *scene_;
    QPointF startFastLanding;

    QRect boundingRectangale;
    int max_col = 0, max_row = 0;

    bool isFastLanding = false;

    qreal angle, speed, paused_speed;

};

#endif // FIGURES_H
