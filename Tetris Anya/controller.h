#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE

class Controller : public QMainWindow {
public:
    Controller(QWidget *parent = 0);
    ~Controller();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Controller *ui;
};

#endif // CONTROLLER_H
