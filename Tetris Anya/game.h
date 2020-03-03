#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();


private:
    Ui::game *ui;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // GAME_H
