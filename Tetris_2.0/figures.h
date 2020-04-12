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

const std::size_t NUM_OF_BLOCKS = 4;
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
    Tetrimino(std::vector<int> blocks, tetriminoes type, Field *f);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setCoordinates(int start);

    std::vector<std::pair<int, int>> _blocks;
    QPointF highLeftCorner;

    int maxParm(bool parm);
    void turn90back();
    void turn90up();

protected:
    void advance(int phase) override;
    //void keyPressEvent(QKeyEvent *event) override;

private:
    static const std::size_t BLOCK_H = 2;
    static const std::size_t BLOCK_W = 4;
    static const int BLOCK_PX = 25;
    static const int PADDING = 5;

    tetriminoes type_;
    QColor color_;
    Field *field;

    qreal angle, speed;
};

#endif // FIGURES_H
