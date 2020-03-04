#include "controller.h"
#include "ui_controller.h"
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>

Controller::Controller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Controller)
{
    ui->setupUi(this);
}

Controller::~Controller()
{
    delete ui;
}

void Controller::KeyPressEvent(QKeyEvent *event) {

    qDebug() << "I am here!";

    if (event->key() == Qt::Key_Left) {
        qDebug() << "Left!";
    }

    if (event->key() == Qt::Key_Right) {
        qDebug() << "Right!";
    }

    /*if (event->key() == Qt::Key_Escape) {
        qDebug() << "Good Bye!";
        qApp->quit();
    }*/
}
