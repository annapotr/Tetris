#include "controller.h"

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

void Controller::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Up) {
        //calling the function of turning to 90 degrees onward
        //
        qDebug() << "Turn 90 onward!";
    }

    if (event->key() == Qt::Key_Down) {
        //calling the function of turning to 90 degrees backward
        //
        qDebug() << "Turn 90 backward!";
    }

    if (event->key() == Qt::Key_Left) {
        //calling the function of left moving
        //
        qDebug() << "Left!";
    }

    if (event->key() == Qt::Key_Right) {
        //calling the function of right moving
        //
        qDebug() << "Right!";
    }

    if (event->key() == Qt::Key_Space) {
        //calling the function of fast landing
        //
        qDebug() << "Fast landing!";
    }
}
