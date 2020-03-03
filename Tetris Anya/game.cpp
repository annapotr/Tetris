#include "game.h"
#include "ui_game.h"
#include "myitem.h"
#include "figures.h"
#include <QTimer>
#include <QElapsedTimer>

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setStyleSheet("background-color:rgb(61, 36, 75);");
    scene->setSceneRect(1,1,260,520);

    QPen mypen = QPen(Qt::red);
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

    qsrand(21);
    Figures *figure = new Figures(3,scene); // можно написать любую цифру из [1,5] в зависимоости от фигуры

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(100);

}

game::~game()
{
    delete ui;
}


