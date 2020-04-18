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

    Ui::Game *ui;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QTimer *timer;
    Field *f;

protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // GAME_H
