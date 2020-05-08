#include "gameover.h"
#include "ui_gameover.h"
#include "game.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QTimer>

GameOver::GameOver(Field *f, QGraphicsScene *scene, QWidget *parent) :
    QDialog(parent),
    f(f),
    ui(new Ui::GameOver),
    scene_(scene)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    close();
    f->updateField(0);

    f->currentTetrimino = f->generateNext(scene_);
    f->currentFallen = f->generateFallen(scene_);

    scene_->addItem(f->currentTetrimino);
    scene_->addItem(f->currentFallen);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene_, SLOT(advance()));
    timer->start(25);

}

void GameOver::on_pushButton_2_clicked()
{
    QApplication::quit();
}
