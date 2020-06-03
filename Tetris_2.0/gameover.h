#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "field.h"
#include "game.h"
#include <QDialog>

namespace Ui {
    class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(Field *f, int score, QGraphicsScene *scene, QWidget *parent = nullptr);
    ~GameOver();
    Field *f;
    QTimer *timer;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameOver *ui;
    QGraphicsScene *scene_;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEOVER_H
