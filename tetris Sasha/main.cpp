#include "controller.h"
#include <QDebug>
#include <QApplication>
#include <QKeyEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w;
    w.show();

    return a.exec();
}
