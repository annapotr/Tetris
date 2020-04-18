#include "iostream"
#include "game.h"
#include "ui_game.h"
#include "myitem.h"
#include "figures.h"
#include "fallen.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QIcon>


Game::Game(Field *f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
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
        f->currentTetrimino = f->generateNext(scene);
        f->currentFallen = f->generateFallen(scene);
        scene->addItem(f->currentTetrimino);
        scene->addItem(f->currentFallen);


        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
        timer->start(25);
    //}

}

Game::~Game() {
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_U) {
        std::cout << "Up!\n";
        //f->currentTetrimino->turn90up();
    }

    if (event->key() == Qt::Key_D) {
        std::cout << "Back!\n";
        //uturn90back();
    }

    if (event->key() == Qt::Key_L) {
        //calling the function of left moving
        //
        qDebug() << "Left!\n";
    }

    if (event->key() == Qt::Key_R) {
        //calling the function of right moving
        //
        qDebug() << "Right!\n";
    }

    if (event->key() == Qt::Key_Space) {
        qDebug() << "Fast landing!\n";
    }
}
