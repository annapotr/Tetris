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

int START_INTERVAL = 100;
int MINIMAL_INTERVAL = 12;

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

    f->_lf = ui->label_figure;
    f->currentTetrimino = f->generateNext(scene);
    f->currentFallen = f->generateFallen(scene);

    scene->addItem(f->currentTetrimino);
    scene->addItem(f->currentFallen);

    timer = new QTimer(this);
    f->timer = timer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(START_INTERVAL);

    f->level_ = ui->label_level_numbers;
    f->score_ = ui->label_score_numbers;
    ui->label_score_numbers->setNum(f->getScore());
    ui->label_score_numbers->setAlignment(Qt::AlignCenter);
    ui->label_level_numbers->setNum(f->getLevel());
    ui->label_level_numbers->setAlignment(Qt::AlignCenter);

}

Game::~Game() {
    delete ui;
    delete scene;
}

void Game::keyPressEvent(QKeyEvent *event) {
    qDebug() << "here!\n";
    if (event->key() == Qt::Key_W) {
        f->currentTetrimino->turn90up();
    }

    if (event->key() == Qt::Key_S) {
        f->currentTetrimino->turn90back();
    }

    if (event->key() == Qt::Key_A) {
        f->currentTetrimino->left();
    }

    if (event->key() == Qt::Key_D) {
        f->currentTetrimino->right();
    }

    if (event->key() == Qt::Key_G) {
        f->currentTetrimino->fastLanding();
    }

    if(event->key() == Qt::Key_P){
        on_pause_clicked();
    }

    if(event->key() == Qt::Key_Escape){
        f->gameState = gameStates::GAMEOVER;
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
