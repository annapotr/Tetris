#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "field.h"

namespace Ui {
    class Game;
}

class Game : public QDialog {
    Q_OBJECT
public:
    explicit Game(Field *f, QWidget *parent = nullptr);
    ~Game();

    void changeImage(int nextFigure);

    //static void doEnd();

    Ui::Game *ui;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QTimer *timer;
    Field *f;


protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

};

#endif // GAME_H
