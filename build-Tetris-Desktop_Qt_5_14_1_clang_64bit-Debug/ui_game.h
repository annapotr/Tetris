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
    QLabel *label_high_score;
    QPushButton *pushButton;

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
        Close_game->setGeometry(QRect(319, 20, 171, 61));
        Close_game->setStyleSheet(QString::fromUtf8("background-image: url(:/close.png);\n"
"border: none;\n"
"\n"
""));
        label_score = new QLabel(Game);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(320, 260, 170, 60));
        label_score->setMaximumSize(QSize(170, 200));
        label_score->setStyleSheet(QString::fromUtf8("background-image: url(:/score.png);\n"
"border: none;"));
        label_score->setAlignment(Qt::AlignCenter);
        label_high_score = new QLabel(Game);
        label_high_score->setObjectName(QString::fromUtf8("label_high_score"));
        label_high_score->setGeometry(QRect(320, 110, 170, 60));
        label_high_score->setStyleSheet(QString::fromUtf8("background-image: url(:/high_score.png);"));
        label_high_score->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 460, 170, 60));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pause.png);\n"
"border: none;"));

        retranslateUi(Game);
        QObject::connect(Close_game, SIGNAL(clicked()), Game, SLOT(close()));

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Dialog", nullptr));
        Close_game->setText(QString());
        label_score->setText(QString());
        label_high_score->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
