#include "game.h"
#include "ui_game.h"
#include "myitem.h"
#include "figures.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QIcon>


game::game(Field *f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);


    
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0,0,260,520);

    QBrush br(QImage(":\background.png"));
    QPalette plt = this->palette();
    plt.setBrush(QPalette::Background, br);
    this->setPalette(plt);
/*
    QPen mypen = QPen();
    mypen.setWidth(5);
    mypen.setStyle(Qt::SolidLine);
    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);
*/

    Figures *figure = new Figures(1,f); // можно написать любую цифру из [1,5] в зависимоости от фигуры
    scene->addItem(figure);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(50);

}
/*
void game::newFigure(){
    Figures *figure = new Figures(1,scene); // можно написать любую цифру из [1,5] в зависимоости от фигуры
    scene->addItem(figure);
}*/


game::~game()
{
    delete ui;
}


