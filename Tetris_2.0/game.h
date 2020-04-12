#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "field.h"

namespace Ui {
    class game;
}

class game : public QDialog {
    Q_OBJECT
public:
    explicit game(Field *f, QWidget *parent = nullptr);
    ~game();

    Ui::game *ui;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QTimer *timer;
    Field *f;
};

#endif // GAME_H
