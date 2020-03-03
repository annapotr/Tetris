#ifndef FIGURES_H
#define FIGURES_H
#include <QGraphicsScene>


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

};

#endif // FIGURES_H
