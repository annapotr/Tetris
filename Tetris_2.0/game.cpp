#include "game.h"
#include "ui_game.h"
#include "myitem.h"
#include "figures.h"
#include "field.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QIcon>
#include <iostream>


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

    srand(time(NULL));
    while(f->getState()) {
        f->currentTetrimino = f->generateNext();
        scene->addItem(f->currentTetrimino);
        f->fill();
    }

//    timer = new QTimer(this);
//    connect(timer, SIGNAL(), scene, SLOT(advance()));
//    timer->start(50);

    f-> printFieldTmp();
}

game::~game()
{
    delete ui;
}


