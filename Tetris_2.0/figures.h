#ifndef FIGURES_H
#define FIGURES_H
#include <QColor>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include "field.h"

class Field;

const std::size_t NUM_OF_BLOCKS = 4;
extern std::array<std::array<int, 4>, 7> tetriminoesInit;
enum class tetriminoes: int {
    I = 1,
    J = 2,
    L = 3,
    O = 4,
    S = 5,
    T = 6,
    Z = 7
};

QColor make_color(tetriminoes t);

class Figures : public QGraphicsItem
{
public:
    Figures(std::array<int, NUM_OF_BLOCKS> blocks, tetriminoes type);

    void falling();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setCoordinates(Field *f, int start);

    bool isFalling = true;
    std::array<std::pair<float,float>, 4> items;

protected:
    void advance(int phase) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    static const std::size_t BLOCK_H = 2;
    static const std::size_t BLOCK_W = 4;

    std::array<std::array<bool, BLOCK_W>, BLOCK_H> _blocks;
    tetriminoes type_;
    QColor color_;

    qreal angle;
    qreal speed;
};

#endif // FIGURES_H
