#include "figures.h"
#include "myitem.h"


Figures::Figures(int type, QGraphicsScene *scene)
{
    if(type == 1) Figure_1(scene);
    if(type == 2) Figure_2(scene);
    if(type == 3) Figure_3(scene);
    if(type == 4) Figure_4(scene);
    if(type == 5) Figure_5(scene);
}

void Figures::Figure_1(QGraphicsScene *scene)
{
    MyItem *item1 = new MyItem(80,5);
    scene->addItem(item1);
    MyItem *item2 = new MyItem(105,5);
    scene->addItem(item2);
    MyItem *item3 = new MyItem(130,5);
    scene->addItem(item3);
    MyItem *item4 = new MyItem(155,5);
    scene->addItem(item4);
}

void Figures::Figure_2(QGraphicsScene *scene)
{
    MyItem *item1 = new MyItem(80,5);
    scene->addItem(item1);
    MyItem *item2 = new MyItem(105,5);
    scene->addItem(item2);
    MyItem *item3 = new MyItem(130,5);
    scene->addItem(item3);
    MyItem *item4 = new MyItem(105,30);
    scene->addItem(item4);
}

void Figures::Figure_3(QGraphicsScene *scene)
{
    MyItem *item1 = new MyItem(105,5);
    scene->addItem(item1);
    MyItem *item2 = new MyItem(130,5);
    scene->addItem(item2);
    MyItem *item3 = new MyItem(105,30);
    scene->addItem(item3);
    MyItem *item4 = new MyItem(130,30);
    scene->addItem(item4);
}

void Figures::Figure_4(QGraphicsScene *scene)
{
    MyItem *item1 = new MyItem(80,5);
    scene->addItem(item1);
    MyItem *item2 = new MyItem(105,5);
    scene->addItem(item2);
    MyItem *item3 = new MyItem(130,5);
    scene->addItem(item3);
    MyItem *item4 = new MyItem(130,30);
    scene->addItem(item4);
}

void Figures::Figure_5(QGraphicsScene *scene)
{
    MyItem *item1 = new MyItem(80,5);
    scene->addItem(item1);
    MyItem *item2 = new MyItem(105,5);
    scene->addItem(item2);
    MyItem *item3 = new MyItem(105,30);
    scene->addItem(item3);
    MyItem *item4 = new MyItem(130,30);
    scene->addItem(item4);
}



