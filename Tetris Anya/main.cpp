#include "mainwindow.h"

#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPixmap br(":/menu.png");
    br = br.scaled(w.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette plt = w.palette();
    plt.setBrush(QPalette::Background, br);
    w.setPalette(plt);
    w.show();
    return a.exec();
}
