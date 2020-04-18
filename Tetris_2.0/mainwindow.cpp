#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_play_clicked()
{
    hide();
    Field *f = new Field(0);
    Game game(f);
    game.setModal(true);
    game.setStyleSheet("background-color:black;");
    game.exec();
}
