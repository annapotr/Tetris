/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QGraphicsView *graphicsView;
    QPushButton *Close_game;
    QLabel *label_score;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_figure;
    QLabel *label_score_numbers;

    void setupUi(QDialog *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(503, 574);
        Game->setMinimumSize(QSize(503, 574));
        Game->setMaximumSize(QSize(503, 574));
        Game->setStyleSheet(QString::fromUtf8("background-image: url(:/background1.png);"));
        graphicsView = new QGraphicsView(Game);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 265, 525));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/background.png);\n"
"border: none;"));
        Close_game = new QPushButton(Game);
        Close_game->setObjectName(QString::fromUtf8("Close_game"));
        Close_game->setGeometry(QRect(320, 10, 171, 61));
        Close_game->setStyleSheet(QString::fromUtf8("background-image: url(:/close.png);\n"
"border: none;\n"
"\n"
""));
        label_score = new QLabel(Game);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(320, 330, 170, 60));
        label_score->setMaximumSize(QSize(170, 200));
        label_score->setStyleSheet(QString::fromUtf8("background-image: url(:/score.png);\n"
"border: none;"));
        label_score->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 470, 170, 60));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pause.png);\n"
"border: none;"));
        label = new QLabel(Game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 80, 170, 50));
        label->setMinimumSize(QSize(170, 50));
        label->setMaximumSize(QSize(170, 50));
        label_figure = new QLabel(Game);
        label_figure->setObjectName(QString::fromUtf8("label_figure"));
        label_figure->setGeometry(QRect(320, 190, 170, 100));
        label_figure->setMinimumSize(QSize(170, 100));
        label_figure->setMaximumSize(QSize(179, 100));
        label_score_numbers = new QLabel(Game);
        label_score_numbers->setObjectName(QString::fromUtf8("label_score_numbers"));
        label_score_numbers->setGeometry(QRect(330, 400, 151, 41));
        label_score_numbers->setStyleSheet(QString::fromUtf8("font: 36pt \"Optima\";\n"
"color:rgb(0, 225, 216);"));

        retranslateUi(Game);
        QObject::connect(Close_game, SIGNAL(clicked()), Game, SLOT(close()));

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Dialog", nullptr));
        Close_game->setText(QString());
        label_score->setText(QString());
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("Game", "Level", nullptr));
        label_figure->setText(QCoreApplication::translate("Game", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \321\204\320\270\320\263\321\203\321\200\320\272\320\270", nullptr));
        label_score_numbers->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
