#include "iostream"
#include "game.h"
#include "ui_game.h"
#include "myitem.h"
#include "figures.h"
#include "fallen.h"
#include "field.h"
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

    ui->pause->setStyleSheet("border-image: url(:/pause.png) stretch;");

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(BLOCK_PX, BLOCK_PX, 258, 516);

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
        timer->start(10);

    //}
    f->level_ = ui->label_level_numbers;
    f->score_ = ui->label_score_numbers;
    ui->label_score_numbers->setNum(f->getScore());
    ui->label_score_numbers->setAlignment(Qt::AlignCenter);

}

/*
void Game::doEnd(){
    timer->stop();
}*/


Game::~Game() {
    delete ui;
    delete scene;
}

void Game::keyPressEvent(QKeyEvent *event) {

    //qDebug() << "In KPE\n" << "f->currentTetrimino: " << f->currentTetrimino << "currT->field->currentTetrimino: " << currT->field->currentTetrimino << ", currT: " << currT << ", currT->field: " << currT->field << '\n';

    if (event->key() == Qt::Key_W) {
        //qDebug() << "Up!\n";
        f->currentTetrimino->turn90up();
    }

    if (event->key() == Qt::Key_S) {
        qDebug() << "Back!\n";
        f->currentTetrimino->turn90back();
    }

    if (event->key() == Qt::Key_A) {
        qDebug() << "Left!\n";
        f->currentTetrimino->left();
    }

    if (event->key() == Qt::Key_D) {
        //calling the function of right moving
        //
        qDebug() << "Right!\n";
        f->currentTetrimino->right();
    }

    if (event->key() == Qt::Key_Space) {
        qDebug() << "Fast landing!\n";
        f->currentTetrimino->fastLanding();
    }
}


void Game::on_pause_clicked()
{
    if(f->getState() == gameStates::PAUSED) {
        ui->label_Tetris->clear();
        ui->label_Tetris->setStyleSheet("background: rgba(255, 255, 255, 0)");
        ui->pause->setStyleSheet("border-image: url(:/pause.png) stretch;");
        f->gameState = gameStates::INPROCESS;
    } else {
        ui->label_Tetris->setStyleSheet("background: rgba(255, 255, 255, 255)");
        QPixmap pix(":/tetris.png");
        ui->label_Tetris->setPixmap(pix);
        ui->pause->setStyleSheet("border-image: url(:/continue.png) stretch;");
        f->gameState = gameStates::PAUSED;
    }
}
