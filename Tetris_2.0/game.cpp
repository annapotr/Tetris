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
#include <random>


Game::Game(Field *f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game),
    f(f)
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
        f->_lf = ui->label_figure;

        f->currentTetrimino = f->generateNext(scene);
        f->currentFallen = f->generateFallen(scene);

        scene->addItem(f->currentTetrimino);
        scene->addItem(f->currentFallen);

        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
        timer->start(25);

    //}
    ui->label_score_numbers->setNum(f->getScore());
    ui->label_score_numbers->setAlignment(Qt::AlignCenter);
    /*
    switch(f->getNextFigure()) {
        case(0): {
            QPixmap pix(":/redBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(1): {
            QPixmap pix(":/yellowBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(2): {
            QPixmap pix(":/blueBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(3): {
            QPixmap pix(":/pinkBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(4): {
            QPixmap pix(":/redBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(5): {
            QPixmap pix(":/redBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
        case(6): {
            QPixmap pix(":/redBlocks.png");
            ui->label_figure->setPixmap(pix);
        }
    }*/



}

/*
void Game::doEnd(){
    timer->stop();
}*/


Game::~Game() {
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *event) {

    //qDebug() << "In KPE\n" << "f->currentTetrimino: " << f->currentTetrimino << "currT->field->currentTetrimino: " << currT->field->currentTetrimino << ", currT: " << currT << ", currT->field: " << currT->field << '\n';

    if (event->key() == Qt::Key_U) {
        //qDebug() << "Up!\n";
        f->currentTetrimino->turn90up();
    }

    if (event->key() == Qt::Key_D) {
        qDebug() << "Back!\n";
        f->currentTetrimino->turn90back();
    }

    if (event->key() == Qt::Key_L) {
        qDebug() << "Left!\n";
        f->currentTetrimino->left();
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


