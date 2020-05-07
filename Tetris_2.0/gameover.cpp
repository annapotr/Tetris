#include "gameover.h"
#include "ui_gameover.h"
#include "game.h"
#include <iostream>
#include <QApplication>

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
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
    hide();
    Field *f = new Field(0);
    Game game(f);
    game.setModal(true);
    game.exec();
}

void GameOver::on_pushButton_2_clicked()
{
    QApplication::quit();
}
