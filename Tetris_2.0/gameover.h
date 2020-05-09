#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <field.h>
#include <game.h>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(Field *f, QGraphicsScene *scene, QWidget *parent = nullptr);
    ~GameOver();
    Field *f;
    QTimer *timer;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameOver *ui;
    QGraphicsScene *scene_;
};

#endif // GAMEOVER_H
