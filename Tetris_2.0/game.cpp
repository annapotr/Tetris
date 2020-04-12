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

    //while(f->getState() == gameStates::INPROCESS) {
        //timer->stop();
        f->currentTetrimino = f->generateNext(scene); // можно написать любую цифру из [1,5] в зависимоости от фигуры
        scene->addItem(f->currentTetrimino);

        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
        timer->start(100);
    //}

}

game::~game() {
    delete ui;
}
