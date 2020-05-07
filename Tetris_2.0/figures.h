#ifndef FIGURES_H
#define FIGURES_H

#include <QColor>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QPointF>
#include <vector>
#include <utility>
#include "field.h"

class Field;

extern int BLOCK_PX;
extern int PADDING;

constexpr std::size_t NUM_OF_BLOCKS = 4;

extern std::vector<std::vector<int>> tetriminoesInit;
enum class tetriminoes: int {
    I = 0,
    J = 1,
    L = 2,
    O = 3,
    S = 4,
    T = 5,
    Z = 6
};

QColor make_color(tetriminoes t);

class Tetrimino : public QGraphicsItem {
public:
    Tetrimino(std::vector<int> blocks, tetriminoes type, Field *f, QGraphicsScene *scene);//, QGraphicsScene *scene);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setCoordinates(int start);
    void left();
    void right();

    std::vector<std::pair<int, int>> _blocks;
    QPointF topLeftCorner;

    int maxParam(bool param);
    int minParam(bool param);
    void turn90back();
    void turn90up();


protected:
    void advance(int phase) override;

private:
    static const std::size_t BLOCK_H = 2;
    static const std::size_t BLOCK_W = 4;

    tetriminoes type_;
    QPixmap pix_;
    //QColor color_;
    Field *field;
    QGraphicsScene *scene_;

    QRect boundingRectangale;
    std::size_t max_col = 0, max_row = 0;

    bool isVertical = 0;

    qreal angle, speed;
};

#endif // FIGURES_H
