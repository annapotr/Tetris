#include "ui_gameover.h"
#include "gameover.h"
#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QTimer>

GameOver::GameOver(Field *f,int score_, QGraphicsScene *scene, QWidget *parent) :
    QDialog(parent),
    f(f),
    ui(new Ui::GameOver),
    scene_(scene)
{
    grabKeyboard();
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    ui->score->setNum(score_);
    ui->score->setAlignment(Qt::AlignCenter);
}

GameOver::~GameOver() {
    delete ui;
}

void GameOver::on_pushButton_clicked() {
    releaseKeyboard();
    close();

    f->updateField(0, scene_);

    f->currentTetrimino = f->generateNext(scene_);
    f->currentFallen = f->generateFallen(scene_);

    scene_->addItem(f->currentTetrimino);
    scene_->addItem(f->currentFallen);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene_, SLOT(advance()));
    timer->start(START_INTERVAL);    
}

void GameOver::on_pushButton_2_clicked() {
    QApplication::quit();
}

void GameOver::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Escape){
        QApplication::quit();
    }
    if(event->key() == Qt::Key_Space){
        on_pushButton_clicked();
    }
}
