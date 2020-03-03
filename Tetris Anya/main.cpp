#include "mainwindow.h"

#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color:black;");
    w.show();
    return a.exec();
}
